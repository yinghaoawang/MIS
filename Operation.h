#ifndef OPERATION_H_
#define OPERATION_H_
#include <iostream>
#include <vector>
#include "Token.h"

class Operation {
  protected:
    std::vector<Token> params;
  public:
    virtual void Init()=0;
    virtual Operation* Clone()=0;
    virtual void Execute()=0;
    virtual void SetParams(std::vector<Token> &param_tok) {
      for (auto it = param_tok.begin(); it != param_tok.end(); ++it) {
        params.push_back(*it);
      }
    }
};

class VarOperation : public Operation {
  public:
    VarOperation() { Init(); }
    virtual void Init() {}
    virtual Operation *Clone() {
      VarOperation *o = new VarOperation();
      o->Init();
      return o;
    }
    virtual void Execute() {
      std::cout << "this is a var operation: does nothing at execute" << std::endl;
    }
};

class AddOperation : public Operation {
  public:
    AddOperation() { Init(); }
    virtual void Init() {
    }

    virtual Operation* Clone() {
      AddOperation *o = new AddOperation();
      o->Init();
      return o;
    }

    virtual void Execute() {
      std::cout << "this is an add operation" << std::endl;
      double dsum = 0.0;
      long lsum = 0;
      Token *dest_tok = &params.front();
      for (auto it = params.begin(); it != params.end(); ++it) {
        if (it == params.begin()) continue;
        if (it->IsNumeric()) {
        std::cout << "numeric: " << it->GetAsNumeric() << std::endl;
          dsum += it->GetAsNumeric();
          lsum += it->GetAsNumeric();
        }
        if (it->IsReal()) {
        std::cout << "real: " << it->GetAsReal() << std::endl;
          dsum += it->GetAsReal();
          lsum += it->GetAsReal();
        }
      }
      Data *data;
      if (dest_tok->IsNumeric()) data = new Data(dsum);
      if (dest_tok->IsReal()) data = new Data(lsum);
      dest_tok->SetVariableData(*data);
      std::cout << dest_tok->GetAsNumeric() << std::endl;
    }
};

class SubOperation : public Operation {
  public:
    SubOperation() { Init(); }
    virtual void Init() {
    }

    virtual Operation* Clone() {
      SubOperation *o = new SubOperation();
      o->Init();
      return o;
    }
    virtual void Execute() {
      std::cout << "this is an sub operation" << std::endl;

      Token *dest_tok = &params.front();

      double ddiff = 0.0;
      long ldiff = 0;

      if (params[1].IsNumeric()) {
        ddiff += params[1].GetAsNumeric();
        ldiff += params[1].GetAsNumeric();
      } else {
        ddiff += params[1].GetAsReal();
        ldiff += params[1].GetAsReal();
      }

      if (params[2].IsNumeric()) {
        ddiff -= params[2].GetAsNumeric();
        ldiff -= params[2].GetAsNumeric();
      } else {
        ddiff -= params[2].GetAsNumeric();
        ldiff -= params[2].GetAsNumeric();
      }

      Data *data;
      if (dest_tok->IsNumeric()) data = new Data(ddiff);
      if (dest_tok->IsReal()) data = new Data(ldiff);

      dest_tok->SetVariableData(*data);
      std::cout << dest_tok->GetAsNumeric() << std::endl;
    }
};

#endif
