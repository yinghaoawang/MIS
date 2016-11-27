#ifndef ADDOPERATION_H_
#define ADDOPERATION_H_
#include "Operation.h"
class AddOperation : public Operation {
  public:
    AddOperation();
    virtual Operation* Clone();
    virtual std::string Execute(int&);
};
#endif
