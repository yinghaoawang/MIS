#include "JmpglteParser.h"

JmpglteParser::JmpglteParser() {}
Parser *JmpglteParser::Clone() { return new JmpglteParser(); }
std::vector<Token> JmpglteParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 3, 3);

  Token t1 = StrToLabelTok(cache, str_toks[0]);
  Token t2 = StrToNumTok(cache, str_toks[1]);
  Token t3 = StrToNumTok(cache, str_toks[2]);
  tokens.push_back(t1);
  tokens.push_back(t2);
  tokens.push_back(t3);
  return tokens;
}
