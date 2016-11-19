#ifndef VARPARSER_H_
#define VARPARSER_H_

#include "Parser.h"

class VarParser : public Parser {
  private:
    bool HasValidVarType(const std::string&, const std::string&, const std::string&);
    Token VarToTok(const std::string&, const std::string&, const std::string&, int);
    bool HasValidStringSize(const std::string&, size_t);
    void SetVariable(const std::vector<std::string>&, std::string&, std::string&, std::string&, int&);

  public:
    VarParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&);
};
#endif
