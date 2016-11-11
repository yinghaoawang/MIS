#ifndef OPERATIONFACTORY_H_
#define OPERATIONFACTORY_H_

#include "AbstractFactory.h"
#include <map>

class OperationFactory : public AbstractFactory {
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
