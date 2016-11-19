#ifndef JMPOPERATION_H_
#define JMPOPERATION_H_
#include "Operation.h"
class JmpOperation : public Operation {
  public:
    JmpOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
