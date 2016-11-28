#ifndef OUTPARSER_H_
#define OUTPARSER_H_

#include "Parser.h"

class OutParser : public Parser {
  public:
    OutParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str);
};
#endif
