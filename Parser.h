#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <map>
#include <exception>
#include "OperationFactory.h"
#include "Operation.h"
#include "Token.h"
#include "Variable.h"
#include "Util.h"
#include "Cache.h"

class Parser {
  protected:
    bool HasValidParamsCount(int, int, int);

  public:
    virtual Parser *Clone()=0;
    virtual std::vector<Token> Tokenize(Cache *, std::string&)=0;

    Operation *ParseOp(Cache *cache, std::string &line, std::string &op_name) {
      OperationFactory *operation_factory = new OperationFactory();

      std::vector<Token> tokens;

      std::cout << op_name << ": ";
      std::cout << line << std::endl;

      try {
        tokens = Tokenize(cache, line);
      } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
      }

      auto operation = (operation_factory->GetOperation(op_name))->Clone();

      operation->SetParams(tokens);
      return operation;
    }
};

bool Parser::HasValidParamsCount(int params_count, int min, int max) {
  if (params_count < min || params_count > max) {
    std::string str_err = "wrong param count: expected " + std::to_string(min) + "-" + std::to_string(max) + ", got " + std::to_string(params_count);
    throw std::runtime_error(str_err);
  }
  return true;
}

class AddParser : public Parser {
  public:
    AddParser() {}
    virtual Parser *Clone() {
      Parser *p = new AddParser();
      return p;
    }

    virtual std::vector<Token> Tokenize(Cache *cache, std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);

      remove_vector_front(str_toks);

      HasValidParamsCount(str_toks.size(), 3, 13);

      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {

        if (str_is_variable(*it)) {
          std::string varname = it->substr(1);
          std::cout << "IS VARIABLE: " << *it << std::endl;

          if (!cache->HasVariable(varname)) {
            std::string str_err = "variable does not exist: " + varname;
            throw std::runtime_error(str_err);
          }
          Variable *v = cache->GetVariable(varname);
          Token t = Token(v);
          tokens.push_back(t);

        } else if (str_is_numeric(*it)) {
          std::cout << "IS NUMERIC: " << *it << std::endl;
          //double d = atof(str.c_str());
          double d = std::stod(*it);
          std::cout << d << std::endl;
          Token t = Token(d);
          tokens.push_back(t);

        } else if (str_is_real(*it)) {
          std::cout << "IS REAL: " << *it << std::endl;
          long l = std::stol(*it);
          Token t = Token(l);
          tokens.push_back(t);

        } else {
          std::string str_err = "bad param type for add operation: " + *it;
          throw std::runtime_error(str_err);
        }

      }

      return tokens;
    }
};

class SubParser : public Parser {
  public:
    SubParser() {}
    virtual Parser *Clone() {
      Parser *p = new SubParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache *cache, std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      // get rid of operation name token
      str_toks.erase(str_toks.begin());

      HasValidParamsCount(str_toks.size(), 3, 3);

      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {

        if (str_is_variable(*it)) {
          std::string varname = it->substr(1);
          if (!cache->HasVariable(varname)) {
            std::string str_err = "variable does not exist: " + varname;
            throw std::runtime_error(str_err);
          }
          Variable *v = cache->GetVariable(varname);
          Token t = Token(v);
          tokens.push_back(t);
        }

      }

      return tokens;
    }
};

#endif
