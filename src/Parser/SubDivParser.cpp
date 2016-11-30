#include "SubDivParser.h"
SubDivParser::SubDivParser() {}
Parser *SubDivParser::Clone() {
  Parser *p = new SubDivParser();
  return p;
}
std::vector<Token> SubDivParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);
  HasValidParamsCount(str_toks.size(), 3, 3);
  Token t = StrToNumTok(cache, str_toks.front());
  if (!t.IsVariable()) {
    std::string str_err = "requires variable as first param, given: " + str_toks.front();
    throw std::runtime_error(str_err);
  }
  if (!cache->HasVariable(t)) {
    std::string str_err = "variable " + std::string(t.GetVariable()->GetName()) + " does not exist";
    throw std::runtime_error(str_err);
  }

  for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
    tokens.push_back(StrToNumTok(cache, *it));
  }
  return tokens;
}
