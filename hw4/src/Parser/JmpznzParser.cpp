#include "Parser/JmpznzParser.h"

JmpznzParser::JmpznzParser() {}
Parser *JmpznzParser::Clone() { return new JmpznzParser(); }
std::vector<Token> JmpznzParser::Tokenize(Cache * const cache, const  std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 2, 2);
  Token t1 = StrToLabelTok(cache, str_toks[0]);
  Token t2 = StrToNumTok(cache, str_toks[1]);
  tokens.push_back(t1);
  tokens.push_back(t2);
  return tokens;
}
