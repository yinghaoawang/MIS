#ifndef VAROPERATION_H_
#define VAROPERATION_H_
#include "Operation.h"
class VarOperation : public Operation {
  public:
    VarOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
