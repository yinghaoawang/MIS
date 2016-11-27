#include "Operation/LabelOperation.h"
LabelOperation::LabelOperation() {}
Operation *LabelOperation::Clone() {
  LabelOperation *o = new LabelOperation();
  return o;
}
void LabelOperation::Execute(int &prog_counter) {}

