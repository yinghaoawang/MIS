#include "Operation/Operation.h"

void Operation::SetParams(std::vector<Token> &param_tok) {
  for (auto it = param_tok.begin(); it != param_tok.end(); ++it) {
    params.push_back(*it);
  }
}
