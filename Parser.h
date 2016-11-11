#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "Operation.h"
#include "FactoryProducer.h"
#include "Token.h"
#include "Util.h"

class Parser {
  public:
    Parser() {}
    virtual Parser *Clone()=0;

    virtual std::vector<Token> Tokenize(std::string&)=0;

    Operation *ParseOp(std::string &str) {
      FactoryProducer fp = FactoryProducer();
      auto ap = fp.GetFactory("OPERATION");

      std::vector<Token> tokens = Tokenize(str);

      std::string opname;
      std::string line;
      get_opname_line(str, opname, line);

      auto operation = (ap->GetOperation(opname))->Clone();

      if (tokens.size() < operation->GetMinParams() + 1 ||
          tokens.size() > operation->GetMaxParams() + 1) {
        std::cerr << "Wrong amount of parameters for operation: ";
        std::cerr << "Got " << tokens.size() - 1 << " need ";
        std::cerr << operation->GetMinParams() << "-";
        std::cerr << operation->GetMaxParams() << std::endl;
        delete ap;
        return nullptr;
      }
      operation->SetParams(tokens);
      delete ap;
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
