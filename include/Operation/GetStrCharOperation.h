#ifndef GETSTRCHAROPERATION_H_
#define GETSTRCHAROPERATION_H_
#include "Operation.h"
class GetStrCharOperation : public Operation {
  public:
    GetStrCharOperation();
    virtual Operation *Clone();
    virtual std::string Execute(int &prog_counter);
};
#endif
