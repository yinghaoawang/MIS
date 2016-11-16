#include "VarParser.h"

// Public
VarParser::VarParser() {}
Parser *VarParser::Clone() {
  Parser *p = new VarParser();
  return p;
}
std::vector<Token> VarParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::string opname;
  std::vector<std::string> str_toks = split_line_getopname(str, opname);

  std::string var_name;
  std::string var_type;
  std::string var_data;
  int var_strlen;

  SetVariable(str_toks, var_name, var_type, var_data, var_strlen);
  HasValidVarType(var_name, var_type, var_data);
  if (var_type == "STRING" || var_type == "CHAR") {
    var_data = cut_quotes(var_data);
  }

  Token t = VarToTok(var_name, var_type, var_data, var_strlen);
  cache->SetVariable(t.GetVariable());
  tokens.push_back(t);
  return tokens;
}

// Private
bool VarParser::HasValidVarType(const std::string &var_name, const std::string &var_type, const std::string &var_data) {
  if (var_type == "NUMERIC" && !str_is_numeric(var_data)) {
    std::string str_err = "not of type NUMERIC: " + var_data;
    throw std::runtime_error(str_err);
  }
  if (var_type == "REAL" && !str_is_real(var_data)) {
    std::string str_err = "not of type REAL: " + var_data;
    throw std::runtime_error(str_err);
  }
  if (var_type == "CHAR" && !str_is_char(var_data)) {
    std::string str_err = "not of type CHAR: " + var_data;
    throw std::runtime_error(str_err);
  }
  if (var_type == "STRING" && !str_is_string(var_data)) {
    std::string str_err = "not of type STRING: " + var_data;
    throw std::runtime_error(str_err);
  }
  return true;
}
Token VarParser::VarToTok(const std::string &var_name, const std::string &var_type, const std::string &var_data, int var_strlen) {
  Data data;
  if (var_type == "NUMERIC") {
    double d = std::stod(var_data);
    data = Data(d);
  } else if (var_type == "REAL") {
    long l = stol(var_data);
    data = Data(l);
  } else if (var_type == "CHAR") {
    char c = stringtochar(var_data);
    data = Data(c);
  } else if (var_type == "STRING") {
    data = Data(var_data, var_strlen);
  } else {
    std::string str_err = "invalid variable type: " + var_type;
    throw std::runtime_error(str_err);
  }
  Variable *v = new Variable(var_name, data);
  Token t = Token(v);
  return t;
}

bool VarParser::HasValidStringSize(const std::string &str, size_t size) {
  if (str.size() - 2 > size) {
    std::string str_err = "string size greater than specified size: " + std::to_string(str.size() - 2) + " > " + std::to_string(size);
    throw std::runtime_error(str_err);
  }
  return true;
}

void VarParser::SetVariable(std::vector<std::string> const &str_toks, std::string &var_name, std::string &var_type, std::string &var_data, int var_strlen) {
  var_name = str_toks.at(0);
  if (!str_is_variable(var_name)) {
    std::string str_err = "invalid string name: " + var_name;
    throw std::runtime_error(str_err);
  }
  var_name.erase(var_name.begin());
  if (str_toks.size() >= 2 && str_toks.at(1) == "STRING") {
    HasValidParamsCount(str_toks.size(), 4, 4);
    var_type = str_toks.at(1);
    var_strlen = std::stoi(str_toks.at(2));
    var_data = str_toks.at(3);
    HasValidStringSize(var_data, var_strlen);
  } else {
    HasValidParamsCount(str_toks.size(), 3, 3);
    var_type = str_toks.at(1);
    var_data = str_toks.at(2);
  }

}
