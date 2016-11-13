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

    Token StrToNumTok(Cache *cache, std::string &str) {
      if (str_is_variable(str)) {
        std::string varname = str.substr(1);

        if (!cache->HasVariable(varname)) {
          std::string str_err = "variable does not exist: " + varname;
          throw std::runtime_error(str_err);
        }

        Variable *v = cache->GetVariable(varname);
        return Token(v);
      }

      if (str_is_numeric(str)) {
        double d = std::stod(str);
        std::cout << d << std::endl;
        return Token(d);
      }

      if (str_is_real(str)) {
        long l = std::stol(str);
        return Token(l);
      }

      std::string str_err = "bad param type for add operation: " + str;
      throw std::runtime_error(str_err);
    }

  public:
    virtual Parser *Clone()=0;
    virtual std::vector<Token> Tokenize(Cache*, std::string&)=0;

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
        tokens.push_back(StrToNumTok(cache, *it));
      }

      return tokens;
    }
};

class VarParser : public Parser {
  private:
    bool HasValidVarType(std::string &var_name, std::string &var_type, std::string &var_data) {
      if (var_type == "NUMERIC" && !str_is_numeric(var_data)) {
        std::string str_err = "not of type NUMERIC: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "REAL" && !str_is_real(var_data)) {
        std::string str_err = "not of type REAL: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "CHAR" && !str_is_char(var_data)) {
        std::string str_err = "not of type NUMERIC: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "STRING" && !str_is_string(var_data)) {
        std::string str_err = "not of type STRING: " + var_data;
        throw std::runtime_error(str_err);
      }
      return true;
    }
    Token VarToTok(std::string &var_name, std::string &var_type, std::string &var_data, int var_strlen) {
      Data data;
        std::cout << var_data << std::endl;
        std::cout << var_data << std::endl;
        std::cout << var_data << std::endl;
      if (var_type == "NUMERIC") {
        double d = std::stod(var_data);
        data = Data(d);
      } else if (var_type == "REAL") {
        //long l = stol(var_data);
        long l = 5;
        data = Data(l);
      } else if (var_type == "CHAR") {
        char c = var_data[0];
        data = Data(c);
      } else if (var_type == "STRING") {
        data = Data(var_data, var_strlen);
      } else {
        std::string str_err = "invalid variable type: " + var_type;
        throw std::runtime_error(str_err);
      }
      Variable *v = new Variable(var_name, data);
      return Token(v);
    }

    Token VarToTok(std::string &var_name, std::string &var_type, std::string &var_data) {
      return VarToTok(var_name, var_type, var_data, 0);
    }

    bool HasValidStringSize(std::string &str, int size) {
      if (str.size() - 2 > size) {
        std::string str_err = "string size greater than specified size: " + std::to_string(str.size() - 2) + " > " + std::to_string(size);
        throw std::runtime_error(str_err);
      }
      return true;
    }

    void SetVariable(std::vector<std::string> const &str_toks, std::string &var_name, std::string &var_type, std::string &var_data, int &var_strlen) {
      var_name = str_toks.at(0);
      if (!str_is_variable(var_name)) {
        std::string str_err = "invalid string name: " + var_name;
        throw std::runtime_error(str_err);
      }
      var_name.erase(var_name.begin());
      if (str_toks.size() >= 2 && str_toks.at(1) == "STRING") {
        HasValidParamsCount(str_toks.size(), 4, 4);
        var_type = str_toks.at(1);
        var_strlen = std::stoi(str_toks.at(2));
        var_data = str_toks.at(3);
        HasValidStringSize(var_data, var_strlen);
      } else {
        HasValidParamsCount(str_toks.size(), 3, 3);
        var_type = str_toks.at(1);
        var_data = str_toks.at(2);
      }

    }

  public:
    VarParser() {}
    virtual Parser *Clone() {
      Parser *p = new VarParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache *cache, std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);

      remove_vector_front(str_toks);

      std::string var_name;
      std::string var_type;
      std::string var_data;
      int var_strlen;

      SetVariable(str_toks, var_name, var_type, var_data, var_strlen);
      HasValidVarType(var_name, var_type, var_data);
      if (var_type == "STRING" || var_type == "CHAR") cut_quotes(var_data);

      Token t = VarToTok(var_name, var_type, var_data, var_strlen);
      cache->SetVariable(t.GetVariable());
      tokens.push_back(t);
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

      remove_vector_front(str_toks);

      HasValidParamsCount(str_toks.size(), 3, 3);

      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
        tokens.push_back(StrToNumTok(cache, *it));
      }

      return tokens;
    }
};

#endif
