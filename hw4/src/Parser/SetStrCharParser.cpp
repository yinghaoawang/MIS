#include "Parser/SetStrCharParser.h"
#include <cstring>
SetStrCharParser::SetStrCharParser() {}
Parser *SetStrCharParser::Clone() {
  return new SetStrCharParser();
}
std::vector<Token> SetStrCharParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 3, 3);
  Token t1 = StrToTok(cache, str_toks.front());
  Token t2 = StrToTok(cache, str_toks.at(1));
  Token t3 = StrToTok(cache, str_toks.at(2));
  if (!t1.IsVariable() ||
      !t1.IsString() ||
      !t2.IsReal() ||
      !t3.IsChar()) {
    std::string str_err = "invalid type for str char operation";
    throw std::runtime_error(str_err);
  }
  if (!cache->HasVariable(t1)) {
    std::string str_err = "variable " + std::string(t1.GetVariable()->GetName()) + " does not exist";
    throw std::runtime_error(str_err);
  }
  int length = t1.GetVariable()->GetStrMaxSize();
  if (length < t2.GetAsReal()) {
    std::string str_err = "variable index out of bounds: " + std::to_string(length) + " < " + std::to_string(t2.GetAsReal());
    throw std::runtime_error(str_err);
  }
  tokens.push_back(t1);
  tokens.push_back(t2);
  tokens.push_back(t3);
  return tokens;
}
