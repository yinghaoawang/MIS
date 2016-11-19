#include "JmpgtOperation.h"
JmpgtOperation::JmpgtOperation() {}
Operation *JmpgtOperation::Clone() {
  return  new JmpgtOperation();
}
void JmpgtOperation::Execute(int &prog_counter) {
  Label *l = params.front().GetLabel();
  Token t2 = params[1];
  Token t3 = params[2];
  bool do_jump = false;
  double d2;
  double d3;
  long l2;
  long l3;
  if (t2.IsNumeric()) {
    d2 = t2.GetAsNumeric();
    l2 = t2.GetAsNumeric();
  } else {
    d2 = t2.GetAsReal();
    l2 = t2.GetAsReal();
  }
  if (t3.IsNumeric()) {
    d3 = t3.GetAsNumeric();
    l3 = t3.GetAsNumeric();
  } else {
    d3 = t3.GetAsReal();
    l3 = t3.GetAsReal();
  }

  if (t2.IsNumeric() && t3.IsNumeric() && d2 > d3) do_jump = true;
  else if (t2.IsNumeric() && t3.IsReal() && d2 > l3) do_jump = true;
  else if (t2.IsReal() && t3.IsNumeric() && l2 > d3) do_jump = true;
  else if (t2.IsReal() && t3.IsReal() && l2 > l3) do_jump = true;

  if (l->GetIndex() >= 0 && do_jump == true) {
    std::cout << "jmpgt: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
    prog_counter = l->GetIndex();
  } else {
    std::cout << "jmpgt: not jumping" << t2.ToString() << "!>" << t3.ToString() << std::endl;
  }
}
