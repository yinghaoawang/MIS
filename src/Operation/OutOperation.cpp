#include "OutOperation.h"
OutOperation::OutOperation() {}
Operation *OutOperation::Clone() {
  return new OutOperation();
}
std::string OutOperation::Execute(int &prog_counter) {
  std::stringstream out;
  out << "out: ";
  for (auto it = params.begin(); it != params.end(); ++it) {
    out << it->ToString() << " ";
  }
  out << std::endl;
  return out.str();
}
