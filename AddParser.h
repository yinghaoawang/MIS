#ifndef ADDPARSER_H_
#define ADDPARSER_H_

#include "Parser.h"

class AddParser : public Parser {
  public:
    AddParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);
};
#endif
