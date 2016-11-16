#ifndef JMPGLTEPARSER_H_
#define JMPGLTEPARSER_H_
#include "Parser.h"
class JmpglteParser : public Parser {
  public:
    JmpglteParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string &);
};
#endif
