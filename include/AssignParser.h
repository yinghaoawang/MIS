#ifndef ASSIGNPARSER_H_
#define ASSIGNPARSER_H_
#include "Parser.h"
class AssignParser : public Parser {
  public:
    AssignParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str);
};
#endif
