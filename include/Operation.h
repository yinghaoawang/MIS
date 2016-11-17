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
    virtual void Execute(int&)=0;
    virtual void SetParams(std::vector<Token> &param_tok) final {
      for (auto it = param_tok.begin(); it != param_tok.end(); ++it) {
        params.push_back(*it);
      }
    }
};

class SleepOperation : public Operation {
  public:
    SleepOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmpltOperation : public Operation {
  public:
    JmpltOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmplteOperation : public Operation {
  public:
    JmplteOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmpgteOperation : public Operation {
  public:
    JmpgteOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmpgtOperation : public Operation {
  public:
    JmpgtOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmpOperation : public Operation {
  public:
    JmpOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};
class JmpzOperation : public Operation {
  public:
    JmpzOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class JmpnzOperation : public Operation {
  public:
    JmpnzOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class LabelOperation : public Operation {
  public:
    LabelOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class VarOperation : public Operation {
  public:
    VarOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class MulOperation : public Operation {
  public:
    MulOperation();
    virtual Operation* Clone();
    virtual void Execute(int &prog_counter);
};

class AddOperation : public Operation {
  public:
    AddOperation() ;
    virtual Operation* Clone();
    virtual void Execute(int &prog_counter);
};

class AssignOperation : public Operation {
  public:
    AssignOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class OutOperation : public Operation {
  public:
    OutOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class DivOperation : public Operation {
  public:
    DivOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class GetStrCharOperation : public Operation {
  public:
    GetStrCharOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class SetStrCharOperation : public Operation {
  public:
    SetStrCharOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

class SubOperation : public Operation {
  public:
    SubOperation();
    virtual Operation *Clone();
    virtual void Execute(int &prog_counter);
};

#endif
