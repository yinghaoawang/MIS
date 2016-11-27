#ifndef DIVOPERATION_H_
#define DIVOPERATION_H_
#include "Operation.h"
class DivOperation : public Operation {
  public:
    DivOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
