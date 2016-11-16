#ifndef STRCHARPARSER_H_
#define STRCHARPARSER_H_
class StrCharParser : public Parser {
  public:
    StrCharParser() {}
    virtual Parser *Clone() {
      return new StrCharParser();
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
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
          !t3.IsVariable() ||
          !t3.IsChar()) {
        std::string str_err = "invalid type for str char operation";
        throw std::runtime_error(str_err);
      }
      tokens.push_back(t1);
      tokens.push_back(t2);
      tokens.push_back(t3);
      return tokens;
    }
};
#endif
