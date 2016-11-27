#include "Operation/JmpOperation.h"
JmpOperation::JmpOperation() {}
Operation *JmpOperation::Clone() {
  JmpOperation *o = new JmpOperation();
  return o;
}
std::string JmpOperation::Execute(int &prog_counter) {
  std::stringstream out;
  Label *l = params.front().GetLabel();
  if (l->GetIndex() >= 0) {
    out << "jmp: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
    prog_counter = l->GetIndex();
  }
  return out.str();
}

