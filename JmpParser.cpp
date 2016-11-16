#include "JmpParser.h"
JmpParser::JmpParser() {}
Parser *JmpParser::Clone() { return new JmpParser(); }
std::vector<Token> JmpParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 1, 1);

  std::string label_name = str_toks.front();
  Token t = StrToLabelTok(cache, label_name);
  tokens.push_back(t);
  return tokens;
}
