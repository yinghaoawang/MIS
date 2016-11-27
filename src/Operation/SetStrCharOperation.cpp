#include "Operation/SetStrCharOperation.h"
SetStrCharOperation::SetStrCharOperation() {}
Operation *SetStrCharOperation::Clone() {
  SetStrCharOperation *o = new SetStrCharOperation;
  return o;
}
void SetStrCharOperation::Execute(int &prog_counter) {
  std::cout << "setstrchar: ";
  Token tokstrvar = params[0];
  Token tokindex = params[1];
  Token tokchar = params[2];
  int index = tokindex.GetAsReal();
  char* string = tokstrvar.GetAsString();
  string[index] = tokchar.GetAsChar();
  std::cout << "set index " + std::to_string(index) + " of " + tokstrvar.GetVariable()->GetName() + " to " + tokchar.ToString() << std::endl;
}
