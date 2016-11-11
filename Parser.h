#ifndef PARSER_H_
#define PARSER_H_

#include "Operation.h"

class Parser {
  public:
    Parser() {}
    virtual void initialize()=0;
    virtual Parser *clone()=0;
    virtual Operation *ParseOp(std::string)=0;
};


class AddParser : public Parser {
  public:
    AddParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new AddParser();
      p->initialize();
      return p;
    }
    virtual Operation *ParseOp(std::string) {
    }
};

class SubParser : public Parser {
  public:
    SubParser() {}
    virtual void initialize() {}
    virtual Parser *clone() {
      Parser *p = new SubParser();
      p->initialize();
      return p;
    }
    virtual Operation *ParseOp(std::string) {

    }

};

#endif
