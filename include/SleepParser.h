#ifndef SLEEPPARSER_H_
#define SLEEPPARSER_H_

#include "Parser.h"

class SleepParser : public Parser {
  public:
    SleepParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);

};
#endif
