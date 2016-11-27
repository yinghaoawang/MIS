#include "Operation/AssignOperation.h"
AssignOperation::AssignOperation() {}
Operation *AssignOperation::Clone() {
  Operation *o = new AssignOperation();
  return o;
}
void AssignOperation::Execute(int &prog_counter) {
  std::cout << "assign: ";
  Token &tok1 = params.at(0);
  Token &tok2 = params.at(1);
  std::cout << tok1.GetVariable()->GetName() << " = " << tok2.ToString() << std::endl;
  tok1.GetVariable()->SetData(*tok2.GetData());
}
