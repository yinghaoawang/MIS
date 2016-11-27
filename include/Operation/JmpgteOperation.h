#ifndef JMPGTEOPERATION_H_
#define JMPTGTEOPERATION_H_
#include "Operation.h"
class JmpgteOperation : public Operation {
  public:
    JmpgteOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
