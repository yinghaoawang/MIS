#ifndef GETSTRCHARPARSER_H_
#define GETSTRCHARPARSER_H_
#include "Parser.h"
class GetStrCharParser : public Parser {
  public:
    GetStrCharParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str);
};
#endif
