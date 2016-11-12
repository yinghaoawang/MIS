#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <map>
#include "OperationFactory.h"
#include "Operation.h"
#include "Token.h"
#include "Variable.h"
#include "Util.h"
#include "Cache.h"

class Parser {
  public:
    virtual Parser *Clone()=0;
    virtual std::vector<Token> Tokenize(std::string&)=0;

    Operation *ParseOp(Cache *cache, std::string &str) {
      OperationFactory *operation_factory = new OperationFactory();

      std::vector<Token> tokens = Tokenize(str);

      std::string opname;
      std::string line;
      get_opname_line(str, opname, line);
      auto operation = (operation_factory->GetOperation(opname))->Clone();

      if (tokens.size() < operation->GetMinParams() ||
          tokens.size() > operation->GetMaxParams()) {
        std::cerr << "Wrong amount of parameters for operation: ";
        std::cerr << "Got " << tokens.size() << " need ";
        std::cerr << operation->GetMinParams() << "-";
        std::cerr << operation->GetMaxParams() << std::endl;
        return nullptr;
      }
      operation->SetParams(tokens);
      return operation;
    }
};


class AddParser : public Parser {
  public:
    AddParser() {}
    virtual Parser *Clone() {
      Parser *p = new AddParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      // get rid of operation name token
      str_toks.erase(str_toks.begin());
      if (str_toks.size() < 3 || str_toks.size() > 13) {
        std::cerr << "wrong param count: " << std::endl;
      }

      static Variable *v = new Variable(5.0);
      Token t = Token(v);
      tokens.push_back(t);
      tokens.push_back(t);
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
    virtual std::vector<Token> Tokenize(std::string &str) {
      std::vector<Token> tokens;
      return tokens;
    }
};

#endif
