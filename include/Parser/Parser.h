#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <map>
#include <exception>
#include "OperationFactory.h"
#include "Operation/Operation.h"
#include "Token.h"
#include "Variable.h"
#include "Util.h"
#include "Cache.h"

class Parser {
  protected:
    Token StrToLabelTok(Cache * const, const std::string &);
    bool HasValidParamsCount(int, int, int);
    Token StrToTok(Cache * const cache, const std::string &);
    Token StrToNumTok(Cache *, std::string &);

  public:
    virtual Parser *Clone()=0;
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&)=0;
    Operation *ParseOp(Cache * const, const std::string&, const std::string&);
};
#endif
