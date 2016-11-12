#ifndef OPERATIONFACTORY_H_
#define OPERATIONFACTORY_H_

#include <string>
#include <map>
#include "Operation.h"

class OperationFactory {
  private:
    static std::map<std::string, Operation*> operations;
    static bool initialized;
  public:
    OperationFactory();
    ~OperationFactory();
    void Init();
    Operation* GetOperation(std::string);
};

#endif
