#ifndef SUBOPERATION_H_
#define SUBOPERATION_H_
#include "Operation.h"
class SubOperation : public Operation {
  public:
    SubOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
