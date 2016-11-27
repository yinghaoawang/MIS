#ifndef JMPTLEOPERATION_H_
#define JMPLTEOPERATION_H_
#include "Operation.h"
class JmplteOperation : public Operation {
  public:
    JmplteOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
