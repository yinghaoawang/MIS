#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "Operation.h"

class Parser {
  public:
    Parser() {}
    virtual void Init()=0;
    virtual Parser *clone()=0;
    virtual Operation *ParseOp(std::string)=0;
};


class AddParser : public Parser {
  public:
    AddParser() {}
    virtual void Init() {
      std::cout << "made an add parser" << std::endl;
    }
    virtual Parser *clone() {
      Parser *p = new AddParser();
      p->Init();
      return p;
    }
    virtual Operation *ParseOp(std::string) {
      return new AddOperation();
    }
};

class SubParser : public Parser {
  public:
    SubParser() {}
    virtual void Init() {}
    virtual Parser *clone() {
      Parser *p = new SubParser();
      p->Init();
      return p;
    }
    virtual Operation *ParseOp(std::string) {
      return new AddOperation();
    }

};

#endif
