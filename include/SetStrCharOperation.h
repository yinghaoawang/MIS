#ifndef SETSTRCHAROPERATION_H_
#define SETSTRCHAROPERATION_H_
#include "Operation.h"
class SetStrCharOperation : public Operation {
  public:
    SetStrCharOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
