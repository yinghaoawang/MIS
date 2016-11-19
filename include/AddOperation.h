#ifndef ADDOPERATION_H_
#define ADDOPERATION_H_
#include "Operation.h"
class AddOperation : public Operation {
  public:
    AddOperation();
    virtual Operation* Clone();
    virtual void Execute(int &prog_counter);
};
#endif
