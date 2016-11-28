#ifndef JMPGTOPERATION_H_
#define JMPGTOPERATION_H_
#include "Operation.h"
class JmpgtOperation : public Operation {
  public:
    JmpgtOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
