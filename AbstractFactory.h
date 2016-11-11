#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

// TODO circular dependency no good
class Parser;
#include "Operation.h"

class AbstractFactory {
  public:
    virtual void Init()=0;
    virtual Parser *GetParser(std::string);
    virtual Operation *GetOperation(std::string);
};

#endif
