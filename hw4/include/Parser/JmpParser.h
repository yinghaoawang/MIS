#ifndef JMPPARSER_H_
#define JMPPARSER_H_
#include "Parser.h"
class JmpParser : public Parser {
  public:
    JmpParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string &);
};
#endif
