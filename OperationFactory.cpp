#include "OperationFactory.h"
#include "Operation.h"

// TODO initialize block doesn't work
std::map<std::string, Operation*> OperationFactory::operations;
bool OperationFactory::initialized;

OperationFactory::OperationFactory() { Init(); }

void OperationFactory::Init() {
  if (!initialized) {
    initialized = true;
    operations["ADD"] = new AddOperation();
    operations["SUB"] = new SubOperation();
  }
}

Operation* OperationFactory::GetOperation(std::string str) {
  if (operations.find(str) != operations.end()) {
    return operations[str]->Clone();
  }
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
