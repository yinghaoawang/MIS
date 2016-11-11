#ifndef PARSER_H_
#define PARSER_H_
#include "strutil.h"

class Parser {
  public:
    Parser() {}
    /*
    void parse_line(std::string &str) {
      std::vector<std::string> strings = split_line(str);
      std::cout << strings.size() << std::endl;

      for (auto it = strings.begin(); it != strings.end(); ++it) {
        std::cout << *it << std::endl;
      }
    }
    */
    virtual void initialize()=0;
    virtual Parser* clone()=0;
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

};

#endif
