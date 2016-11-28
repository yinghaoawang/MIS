#include "OperationFactory.h"
#include "Operation/AddOperation.h"
#include "Operation/SubOperation.h"
#include "Operation/VarOperation.h"
#include "Operation/LabelOperation.h"
#include "Operation/SleepOperation.h"
#include "Operation/JmpOperation.h"
#include "Operation/AssignOperation.h"
#include "Operation/OutOperation.h"
#include "Operation/JmpzOperation.h"
#include "Operation/JmpnzOperation.h"
#include "Operation/JmpgtOperation.h"
#include "Operation/JmpgteOperation.h"
#include "Operation/JmpltOperation.h"
#include "Operation/JmplteOperation.h"
#include "Operation/MulOperation.h"
#include "Operation/DivOperation.h"
#include "Operation/GetStrCharOperation.h"
#include "Operation/SetStrCharOperation.h"

/* Static variables since they will all be cloned: like a pseudo-singleton */
std::map<std::string, Operation*> OperationFactory::operations;
bool OperationFactory::initialized;

OperationFactory::OperationFactory() { Init(); }

/* Create new maps of the operations with their respective operation names as keys */
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
    operations["SET_STR_CHAR"] = new SetStrCharOperation();
  }
}

// Determine if an operation key exists */
bool OperationFactory::HasOperation(const std::string &str) const {
  if (operations.find(str) == operations.end()) return false;
  return true;
}
Operation* OperationFactory::GetOperation(const std::string &str) const {
  if (HasOperation(str)) return operations[str];
  return nullptr;
}

/* Destructor */
OperationFactory::~OperationFactory() {
  if (initialized) {
    initialized = false;
    for (auto it = operations.begin(); it != operations.end(); ++it) {
      delete it->second;
    }
  }
};
