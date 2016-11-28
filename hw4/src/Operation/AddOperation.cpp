#include "Operation/AddOperation.h"
AddOperation::AddOperation() {}

Operation *AddOperation::Clone() {
  AddOperation *o = new AddOperation();
  return o;
}

std::string AddOperation::Execute(int &prog_counter) {
  std::stringstream out;
  out << "add: ";
  double dsum = 0.0;
  long lsum = 0;
  Token dest_tok = params.front();
  for (auto it = params.begin(); it != params.end(); ++it) {
    if (it == params.begin()) continue;
    if (it != params.begin() + 1) out << "+ ";
    if (it->IsNumeric()) {
      out << it->GetAsNumeric() << " ";
      dsum += it->GetAsNumeric();
      lsum += it->GetAsNumeric();
    } else if (it->IsReal()) {
      out << it->GetAsReal() << " ";
      dsum += it->GetAsReal();
      lsum += it->GetAsReal();
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

