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
    bool HasOperation(const std::string&) const;
    Operation* GetOperation(const std::string&) const;
};

#endif
