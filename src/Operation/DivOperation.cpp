#include "Operation/DivOperation.h"
DivOperation::DivOperation() {}
Operation *DivOperation::Clone() {
  DivOperation *o = new DivOperation();
  return o;
}
void DivOperation::Execute(int &prog_counter) {
  std::cout << "div: ";
  Token dest_tok = params.front();

  double ddiff = 0.0;
  long ldiff = 0;
  bool div_by_zero = false;

  Token tok1 = params[1];
  Token tok2 = params[2];

  if (tok1.IsNumeric()) {
    ddiff = tok1.GetAsNumeric();
    ldiff = tok1.GetAsNumeric();
  } else {
    ddiff = tok1.GetAsReal();
    ldiff = tok1.GetAsReal();
  }

  if (tok2.IsNumeric()) {
    if (double_equals(tok2.GetAsNumeric(), 0)) {
      div_by_zero = true;
    } else {
      ddiff /= tok2.GetAsNumeric();
      ldiff /= tok2.GetAsNumeric();
    }
  } else {
    if (tok2.GetAsReal() == 0) {
      div_by_zero = true;
    } else {
      ddiff /= tok2.GetAsReal();
      ldiff /= tok2.GetAsReal();
    }
  }

  std::cout << tok1.ToString() << " / " << tok2.ToString();

  if (div_by_zero) {
    std::cout << std::endl;
    std::string str_err = "cannot divide by zero";
    throw std::runtime_error(str_err);
  }
  Data data;
  if (dest_tok.IsNumeric()) {
    data = Data(ddiff);
  }
  if (dest_tok.IsReal()) {
    data = Data(ldiff);
  }

  dest_tok.SetVariableData(data);
  std::cout << " = " << dest_tok.ToString() << std::endl;
}
