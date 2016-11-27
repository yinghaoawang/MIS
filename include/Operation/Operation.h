#ifndef OPERATION_H_
#define OPERATION_H_
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <exception>
#include "Token.h"
#include "Util.h"

class Operation {
  protected:
    std::vector<Token> params;
  public:
    virtual Operation* Clone()=0;
    virtual std::string Execute(int&)=0;
    virtual void SetParams(std::vector<Token> &param_tok) final;
};

#endif
