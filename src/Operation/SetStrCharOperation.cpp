#include "SetStrCharOperation.h"
SetStrCharOperation::SetStrCharOperation() {}
Operation *SetStrCharOperation::Clone() {
  SetStrCharOperation *o = new SetStrCharOperation;
  return o;
}

std::string SetStrCharOperation::Execute(int &prog_counter) {
  std::stringstream out;
  out << "setstrchar: ";
  Token tokstrvar = params[0];
  Token tokindex = params[1];
  Token tokchar = params[2];
  int index = tokindex.GetAsReal();
  char* string = tokstrvar.GetAsString();
  string[index] = tokchar.GetAsChar();
  out << "set index " + std::to_string(index) + " of " + tokstrvar.GetVariable()->GetName() + " to " + tokchar.ToString() << std::endl;
  return out.str();
}
