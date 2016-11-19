#ifndef MULOPERATION_H_
#define MULOPERATION_H_
#include "Operation.h"
class MulOperation : public Operation {
  public:
    MulOperation();
    virtual Operation* Clone();
    virtual void Execute(int &prog_counter);
};
#endif
