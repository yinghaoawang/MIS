#include "Operation/OutOperation.h"
OutOperation::OutOperation() {}
Operation *OutOperation::Clone() {
  return new OutOperation();
}
void OutOperation::Execute(int &prog_counter) {
  // TODO write to file
  std::cout << "out: ";
  for (auto it = params.begin(); it != params.end(); ++it) {
    std::cout << it->ToString() << " ";
  }
  std::cout << std::endl;
}
