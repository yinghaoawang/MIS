#include "Operation/VarOperation.h"
VarOperation::VarOperation() {}
Operation *VarOperation::Clone() {
  VarOperation *o = new VarOperation();
  return o;
}
std::string VarOperation::Execute(int &prog_counter) { return std::string(""); }
