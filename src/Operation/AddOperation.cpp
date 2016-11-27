#include "Operation/AddOperation.h"
AddOperation::AddOperation() {}

Operation *AddOperation::Clone() {
  AddOperation *o = new AddOperation();
  return o;
}

void AddOperation::Execute(int &prog_counter) {
  std::cout << "add: ";
  double dsum = 0.0;
  long lsum = 0;
  Token dest_tok = params.front();
  for (auto it = params.begin(); it != params.end(); ++it) {
    if (it == params.begin()) continue;
    if (it != params.begin() + 1) std::cout << "+ "; // DEBUG
    if (it->IsNumeric()) {
      std::cout << it->GetAsNumeric() << " "; // DEBUG
      dsum += it->GetAsNumeric();
      lsum += it->GetAsNumeric();
    } else if (it->IsReal()) {
      std::cout << it->GetAsReal() << " "; // DEBUG
      dsum += it->GetAsReal();
      lsum += it->GetAsReal();
    }
  }
  Data data;
  if (dest_tok.IsNumeric()) data = Data((double)dsum);
  if (dest_tok.IsReal()) data = Data((long)lsum);
  dest_tok.SetVariableData(data);

  // DEBUG
  if (dest_tok.IsNumeric()) std::cout << "= " << dest_tok.GetAsNumeric() << std::endl;
  if (dest_tok.IsReal()) std::cout << "= " << dest_tok.GetAsReal() << std::endl;
}

