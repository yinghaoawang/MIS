#include "AssignOperation.h"
AssignOperation::AssignOperation() {}
Operation *AssignOperation::Clone() {
  Operation *o = new AssignOperation();
  return o;
}
std::string AssignOperation::Execute(int &prog_counter) {
  std::stringstream output;
  output << "assign: ";
  Token &tok1 = params.at(0);
  Token &tok2 = params.at(1);
  output << tok1.GetVariable()->GetName() << " = " << tok2.ToString() << std::endl;
  tok1.GetVariable()->SetData(*tok2.GetData());
  return output.str();
}
