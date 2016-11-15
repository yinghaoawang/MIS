#include "OperationFactory.h"

std::map<std::string, Operation*> OperationFactory::operations;
bool OperationFactory::initialized;

OperationFactory::OperationFactory() { Init(); }

void OperationFactory::Init() {
  if (!initialized) {
    initialized = true;
    operations["ADD"] = new AddOperation();
    operations["SUB"] = new SubOperation();
    operations["VAR"] = new VarOperation();
    operations["LABEL"] = new LabelOperation();
    operations["SLEEP"] = new SleepOperation();
    operations["JMP"] = new JmpOperation();
    operations["ASSIGN"] = new AssignOperation();
    operations["OUT"] = new OutOperation();
    operations["JMPZ"] = new JmpzOperation();
    operations["JMPNZ"] = new JmpnzOperation();
    operations["JMPGT"] = new JmpgtOperation();
    operations["JMPGTE"] = new JmpgteOperation();
    operations["JMPLT"] = new JmpltOperation();
    operations["JMPLTE"] = new JmplteOperation();
    operations["MUL"] = new MulOperation();
    operations["DIV"] = new DivOperation();
    operations["GET_STR_CHAR"] = new GetStrCharOperation();
    operations["SET_STR_cHAR"] = new SetStrCharOperation();
  }
}

bool OperationFactory::HasOperation(const std::string &str) const {
  if (operations.find(str) == operations.end()) return false;
  return true;
}

Operation* OperationFactory::GetOperation(const std::string &str) const {
  if (HasOperation(str)) return operations[str];
  return nullptr;
}

OperationFactory::~OperationFactory() {
  if (initialized) {
    initialized = false;
    for (auto it = operations.begin(); it != operations.end(); ++it) {
      delete it->second;
    }
  }
};
