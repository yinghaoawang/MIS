#ifndef SUBDIVPARSER_H_
#define SUBDIVPARSER_H_

#include "Parser.h"

class SubDivParser : public Parser {
  public:
    SubDivParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);
};
#endif
