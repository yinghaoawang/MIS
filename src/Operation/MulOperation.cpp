#include "MulOperation.h"
MulOperation::MulOperation() {}

Operation *MulOperation::Clone() {
  MulOperation *o = new MulOperation();
  return o;
}

std::string MulOperation::Execute(int &prog_counter) {
  std::stringstream out;
  out << "mul: ";
  double dsum = 0.0;
  long lsum = 0;
  Token dest_tok = params.front();
  for (auto it = params.begin(); it != params.end(); ++it) {
    if (it == params.begin()) continue;
    if (it != params.begin() + 1) out << "* "; // DEBUG
    if (it->IsNumeric()) {
      out << it->GetAsNumeric() << " "; // DEBUG
      dsum *= it->GetAsNumeric();
      lsum *= it->GetAsNumeric();
      if (it == params.begin() + 2) {
        dsum = it->GetAsNumeric();
        lsum = it->GetAsNumeric();
      }
    } else if (it->IsReal()) {
      out << it->GetAsReal() << " "; // DEBUG
      dsum *= it->GetAsReal();
      lsum *= it->GetAsReal();
      if (it == params.begin() + 2) {
        dsum = it->GetAsReal();
        lsum = it->GetAsReal();
      }
    }
  }
  Data data;
  if (dest_tok.IsNumeric()) data = Data((double)dsum);
  if (dest_tok.IsReal()) data = Data((long)lsum);
  dest_tok.SetVariableData(data);

  if (dest_tok.IsNumeric()) out << "= " << dest_tok.GetAsNumeric() << std::endl;
  if (dest_tok.IsReal()) out << "= " << dest_tok.GetAsReal() << std::endl;
  return out.str();
}
