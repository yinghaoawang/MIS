#ifndef JMPZNZPARSER_H_
#define JMPZNZPARSER_H_

#include "Parser.h"

class JmpznzParser : public Parser {
  public:
    JmpznzParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const  std::string &);
};

#endif
