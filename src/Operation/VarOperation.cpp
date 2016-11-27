#include "Operation/VarOperation.h"
VarOperation::VarOperation() {}
Operation *VarOperation::Clone() {
  VarOperation *o = new VarOperation();
  return o;
}
void VarOperation::Execute(int &prog_counter) {}
