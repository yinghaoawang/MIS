#include "JmpOperation.h"
JmpOperation::JmpOperation() {}
Operation *JmpOperation::Clone() {
  JmpOperation *o = new JmpOperation();
  return o;
}
void JmpOperation::Execute(int &prog_counter) {
  Label *l = params.front().GetLabel();
  if (l->GetIndex() >= 0) {
    std::cout << "jmp: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
    prog_counter = l->GetIndex();
  }
}

