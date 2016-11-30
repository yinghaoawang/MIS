#include "JmpnzOperation.h"
JmpnzOperation::JmpnzOperation() {}
Operation *JmpnzOperation::Clone() {
  JmpnzOperation *o = new JmpnzOperation();
  return o;
}
std::string JmpnzOperation::Execute(int &prog_counter) {
  std::stringstream out;
  Label *l = params.front().GetLabel();
  Token t2 = params[1];
  bool do_jump = false;
  if (t2.IsNumeric() && !double_equals(t2.GetAsNumeric(), 0.0)) do_jump = true;
  if (t2.IsReal() && t2.GetAsReal() != 0) do_jump = true;
  if (l->GetIndex() >= 0 && do_jump == true) {
    out << "jmpnz: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
    prog_counter = l->GetIndex();
  } else {
    out << "jmpnz: not jumping because " << t2.ToString() << " is zero" << std::endl;
  }
  return out.str();
}
