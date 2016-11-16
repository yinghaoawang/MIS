#include "LabelParser.h"
LabelParser::LabelParser() {}
Parser *LabelParser::Clone() {
  Parser *p = new LabelParser();
  return p;
}
std::vector<Token> LabelParser::Tokenize(Cache * const cache, const std::string &str) {
  std::vector<Token> tokens;
  std::vector<std::string> str_toks = split_line(str);
  remove_opname(str_toks);

  HasValidParamsCount(str_toks.size(), 1, 1);

  std::string label_name = str_toks.front();
  if (!str_is_label(label_name)) {
    std::string str_err = "invalid label name: " + label_name;
    throw std::runtime_error(str_err);
  }

  int op_index = cache->GetOperationSize();

  Label *label;
  if (cache->HasLabel(label_name)) {
    Label *cached_label = cache->GetLabel(label_name);
    if (cached_label->GetIndex() >= 0) {
      std::string str_err = "label already exists " + label_name;
      throw std::runtime_error(str_err);
    }
    cached_label->SetIndex(op_index);
    label = cached_label;
  } else {
    label = new Label(label_name, op_index);
    cache->SetLabel(label);
  }

  Token t = Token(label);
  tokens.push_back(t);

  return tokens;
}
