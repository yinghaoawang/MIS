#include "Parser/SleepParser.h"

SleepParser::SleepParser() {}
Parser *SleepParser::Clone() {
  Parser *p = new SleepParser();
  return p;
}
std::vector<Token> SleepParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 1, 1);

  Token t = StrToNumTok(cache, str_toks.front());
  tokens.push_back(t);
  return tokens;
}
