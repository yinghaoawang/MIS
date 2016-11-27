#ifndef GETSTRCHAROPERATION_H_
#define GETSTRCHAROPERATION_H_
#include "Operation.h"
class GetStrCharOperation : public Operation {
  public:
    GetStrCharOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
