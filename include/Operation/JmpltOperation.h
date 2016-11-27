#ifndef JMPLTOPERATION_H_
#define JMPLTOPERATION_H_
#include "Operation.h"
class JmpltOperation : public Operation {
  public:
    JmpltOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
