#ifndef SLEEPOPERATION_H_
#define SLEEPOPERATION_H_
#include "Operation.h"
class SleepOperation : public Operation {
  public:
    SleepOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
