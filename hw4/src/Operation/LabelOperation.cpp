#include "Operation/LabelOperation.h"
LabelOperation::LabelOperation() {}
Operation *LabelOperation::Clone() {
  LabelOperation *o = new LabelOperation();
  return o;
}
std::string LabelOperation::Execute(int &prog_counter) { return std::string(""); }

