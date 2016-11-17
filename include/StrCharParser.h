#ifndef STRCHARPARSER_H_
#define STRCHARPARSER_H_
#include "Parser.h"
class StrCharParser : public Parser {
  public:
    StrCharParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str);
};
#endif
