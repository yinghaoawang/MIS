#include "SubOperation.h"
SubOperation::SubOperation() {}

Operation *SubOperation::Clone() {
  SubOperation *o = new SubOperation();
  return o;
}
void SubOperation::Execute(int &prog_counter) {
  std::cout << "sub: ";
  Token dest_tok = params.front();

  double ddiff = 0.0;
  long ldiff = 0;

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
    ddiff -= tok2.GetAsNumeric();
    ldiff -= tok2.GetAsNumeric();
  } else {
    ddiff -= tok2.GetAsReal();
    ldiff -= tok2.GetAsReal();
  }

  std::cout << tok1.ToString() << " - " << tok2.ToString();

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
