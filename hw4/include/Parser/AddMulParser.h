#ifndef ADDMULPARSER_H_
#define ADDMULPARSER_H_

#include "Parser.h"

class AddMulParser : public Parser {
  public:
    AddMulParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);
};
#endif
