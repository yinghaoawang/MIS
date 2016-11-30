#include "OutParser.h"

OutParser::OutParser() {}
Parser *OutParser::Clone() {
  return new OutParser();
}
std::vector<Token> OutParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 1, 12);
  for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
    Token t = StrToTok(cache, *it);
    tokens.push_back(t);
  }
  return tokens;
}
