#ifndef JMPNZOPERATION_H_
#define JMPNZOPERATION_H_
#include "Operation.h"
class JmpnzOperation : public Operation {
  public:
    JmpnzOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
#endif
