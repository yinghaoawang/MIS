#include "Parser.h"

Token Parser::StrToLabelTok(Cache * const cache, const std::string &label_name) {
  if (!str_is_label(label_name)) {
    std::string str_err = "invalid label name for jump: " + label_name;
    throw std::runtime_error(str_err);
  }

  Label *label;
  if (cache->HasLabel(label_name)) {
    label = cache->GetLabel(label_name);
  } else {
    label = new Label(label_name, -1);
    cache->SetLabel(label);
  }

  Token t = Token(label);
  return t;
}

bool Parser::HasValidParamsCount(int params_count, int min, int max) {
  if (params_count < min || params_count > max) {
    std::string str_err = "wrong param count: expected " + std::to_string(min) + "-" + std::to_string(max) + ", got " + std::to_string(params_count);
    throw std::runtime_error(str_err);
  }
  return true;
}

Token Parser::StrToTok(Cache * const cache, const std::string &str) {
  if (str_is_variable(str)) {
    std::string varname = str.substr(1);
    if (!cache->HasVariable(varname)) {
      std::string str_err = "variable does not exist: " + varname;
      throw std::runtime_error(str_err);
    }

    Variable *v = cache->GetVariable(varname);
    return Token(v);
  }

  if (str_is_numeric(str)) {
    double d = std::stod(str);
    return Token(d);
  }

  if (str_is_real(str)) {
    long l = std::stol(str);
    return Token(l);
  }

  if (str_is_char(str)) {
    char c = stringtochar(str);
    return Token(c);
  }

  if (str_is_string(str)) {
    std::string tmp = str;
    return Token(cut_quotes(tmp).c_str());
  }

  std::string str_err = "invalid param type: " + str;
  throw std::runtime_error(str_err);
}

Token Parser::StrToNumTok(Cache *cache, std::string &str) {
  Token t = StrToTok(cache, str);
  if (!t.IsNumber()) {
    std::string str_err = "not a number: " + str;
    throw std::runtime_error(str_err);
  }
  return t;
}

Operation *Parser::ParseOp(Cache * const cache, const std::string &line, const std::string &op_name) {
  OperationFactory *operation_factory = new OperationFactory();

  std::vector<Token> tokens;

  tokens = Tokenize(cache, line);

  auto operation = (operation_factory->GetOperation(op_name))->Clone();

  operation->SetParams(tokens);
  return operation;
}
