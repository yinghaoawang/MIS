#ifndef OPERATION_H_
#define OPERATION_H_
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Token.h"

class Operation {
  protected:
    std::vector<Token> params;
  public:
    virtual Operation* Clone()=0;
    virtual void Execute(int&)=0;
    virtual void SetParams(std::vector<Token> &param_tok) {
      for (auto it = param_tok.begin(); it != param_tok.end(); ++it) {
        params.push_back(*it);
      }
    }
};

class SleepOperation : public Operation {
  public:
    SleepOperation() {}
    virtual Operation *Clone() {
      SleepOperation *o = new SleepOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      double seconds;

      Token token = params.at(0);
      if (token.IsReal()) {
        seconds = token.GetAsReal();
      } else {
        seconds = token.GetAsNumeric();
      }
      std::cout << "sleep ex: sleeping for " << seconds << " seconds" << std::endl;
      long ms_to_sleep = seconds * 1000;
      std::this_thread::sleep_for(std::chrono::milliseconds(ms_to_sleep));
    }
};

class JmpOperation : public Operation {
  public:
    JmpOperation() {}
    virtual Operation *Clone() {
      JmpOperation *o = new JmpOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      if (l->GetIndex() >= 0) {
        prog_counter = l->GetIndex();
        std::cout << "setting program counter to the targeted label: " << l->GetName() << " to " << l->GetIndex() << std::endl;
      }
    }
};

class LabelOperation : public Operation {
  public:
    LabelOperation() {}
    virtual Operation *Clone() {
      LabelOperation *o = new LabelOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      std::cout << "this is a label operation: does nothing on execution" << std::endl;
    }
};

class VarOperation : public Operation {
  public:
    virtual Operation *Clone() {
      VarOperation *o = new VarOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      std::cout << "this is a var operation: does nothing at execute" << std::endl;
    }
};

class AddOperation : public Operation {
  public:
    AddOperation() {}

    virtual Operation* Clone() {
      AddOperation *o = new AddOperation();
      return o;
    }

    virtual void Execute(int &prog_counter) {
      // TODO refactor
      std::cout << "this is an add operation" << std::endl;
      double dsum = 0.0;
      long lsum = 0;
      Token dest_tok = params.front();
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
      Data data;
      if (dest_tok.IsNumeric()) data = Data(dsum);
      if (dest_tok.IsReal()) data = Data(lsum);
      dest_tok.SetVariableData(data);
      std::cout << dest_tok.GetAsNumeric() << std::endl;
    }
};

class SubOperation : public Operation {
  public:
    SubOperation() {}

    virtual Operation* Clone() {
      SubOperation *o = new SubOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      // TODO refactor
      std::cout << "this is an sub operation" << std::endl;
      Token dest_tok = params.front();

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

      Data data;
      if (dest_tok.IsNumeric()) data = Data(ddiff);
      if (dest_tok.IsReal()) data = Data(ldiff);

      dest_tok.SetVariableData(data);
      std::cout << dest_tok.GetAsNumeric() << std::endl;
    }
};

#endif
