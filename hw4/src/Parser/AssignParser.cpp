#include "Parser/AssignParser.h"
AssignParser::AssignParser() {}
Parser *AssignParser::Clone() { return new AssignParser(); }

std::vector<Token> AssignParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 2,2);
  std::string varname = str_toks.at(0);
  Variable *v = cache->GetVariable(varname.substr(1));
  if (v == nullptr) {
    std::string str_err = "variable not found: " + varname;
    throw std::runtime_error(str_err);
  }
  Token tok1 = Token(v);
  Token tok2 = StrToTok(cache, str_toks.at(1));


  if (tok1.GetType() != tok2.GetType()) {
    std::string str_err = "non matching get type for assignment";
    throw std::runtime_error(str_err);
  }


  tokens.push_back(tok1);
  tokens.push_back(tok2);
  return tokens;
}
