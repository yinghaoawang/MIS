#ifndef ASSIGNOPERATION_H_
#define ASSIGNOPERATION_H_
#include "Operation.h"
class AssignOperation : public Operation {
  public:
    AssignOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
