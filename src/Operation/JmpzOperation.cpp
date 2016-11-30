#include "JmpzOperation.h"
JmpzOperation::JmpzOperation() {}
Operation *JmpzOperation::Clone() {
  JmpzOperation *o = new JmpzOperation();
  return o;
}
std::string JmpzOperation::Execute(int &prog_counter) {
  std::stringstream out;
  Label *l = params.front().GetLabel();
  Token t2 = params[1];
  bool do_jump = false;
  if (t2.IsNumeric() && double_equals(t2.GetAsNumeric(), 0)) do_jump = true;
  if (t2.IsReal() && t2.GetAsReal() == 0) do_jump = true;
  if (l->GetIndex() >= 0 && do_jump == true) {
    out << "jmpz: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
    prog_counter = l->GetIndex();
  } else {
    out << "jmpz: not jumping because " << t2.ToString() << " is not zero" << std::endl;
  }
  return out.str();
}
