#ifndef SETSTRCHARPARSER_H_
#define SETSTRCHARPARSER_H_
#include "Parser.h"
class SetStrCharParser : public Parser {
  public:
    SetStrCharParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str);
};
#endif
