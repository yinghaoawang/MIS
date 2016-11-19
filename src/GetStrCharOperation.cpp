#include "GetStrCharOperation.h"
GetStrCharOperation::GetStrCharOperation() {}
Operation *GetStrCharOperation::Clone() {
  GetStrCharOperation *o = new GetStrCharOperation;
  return o;
}
void GetStrCharOperation::Execute(int &prog_counter) {
  // TODO
  std::cout << "getstrchar: ";
  Token tokstrvar = params[0];
  Token tokindex = params[1];
  Token tokchar = params[2];
  int index = tokindex.GetAsReal();
  const char* string = tokstrvar.GetAsString();
  char got_c = string[index];
  std::cout << got_c << " into " << tokchar.GetVariable()->GetName() << std::endl;
  tokchar.SetVariableData(Data(got_c));
}
