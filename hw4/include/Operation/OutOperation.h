#ifndef OUTOPERATION_H_
#define OUTOPERATION_H_
#include "Operation.h"
class OutOperation : public Operation {
  public:
    OutOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
