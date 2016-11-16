#ifndef SUBPARSER_H_
#define SUBPARSER_H_

#include "Parser.h"

class SubParser : public Parser {
  public:
    SubParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);
};
#endif
