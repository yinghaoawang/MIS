#ifndef LABELPARSER_H_
#define LABELPARSER_H_
#include "Parser.h"
class LabelParser : public Parser {
  public:
    LabelParser();
    virtual Parser *Clone();
    virtual std::vector<Token> Tokenize(Cache * const, const std::string &);
};
#endif
