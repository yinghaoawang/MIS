#ifndef LABELOPERATION_H_
#define LABELOPERATION_H_
#include "Operation.h"
class LabelOperation : public Operation {
  public:
    LabelOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
