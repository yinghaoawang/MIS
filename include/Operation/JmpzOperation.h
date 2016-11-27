#ifndef JMPZOPERATION_H_
#define JMPZOPERATION_H_
#include "Operation.h"
class JmpzOperation : public Operation {
  public:
    JmpzOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
