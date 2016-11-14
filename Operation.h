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
    virtual void SetParams(std::vector<Token> &param_tok) final {
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
      std::cout << "sleep: " << seconds << " seconds" << std::endl;
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
        std::cout << "jmp: setting program counter to the targeted label " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
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
    virtual void Execute(int &prog_counter) {}
};

class VarOperation : public Operation {
  public:
    virtual Operation *Clone() {
      VarOperation *o = new VarOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {}
};

class AddOperation : public Operation {
  public:
    AddOperation() {}

    virtual Operation* Clone() {
      AddOperation *o = new AddOperation();
      return o;
    }

    virtual void Execute(int &prog_counter) {
      std::cout << "add: ";
      double dsum = 0.0;
      long lsum = 0;
      Token dest_tok = params.front();
      for (auto it = params.begin(); it != params.end(); ++it) {
        if (it == params.begin()) continue;
        if (it != params.begin() + 1) std::cout << "+ "; // DEBUG
        if (it->IsNumeric()) {
          std::cout << it->GetAsNumeric() << " "; // DEBUG
          dsum += it->GetAsNumeric();
          lsum += it->GetAsNumeric();
        } else if (it->IsReal()) {
        std::cout << it->GetAsReal() << " "; // DEBUG
          dsum += it->GetAsReal();
          lsum += it->GetAsReal();
        }
      }
      Data data;
      if (dest_tok.IsNumeric()) data = Data((double)dsum);
      if (dest_tok.IsReal()) data = Data((long)lsum);
      dest_tok.SetVariableData(data);

      // DEBUG
      if (dest_tok.IsNumeric()) std::cout << "= " << dest_tok.GetAsNumeric() << std::endl;
      if (dest_tok.IsReal()) std::cout << "= " << dest_tok.GetAsReal() << std::endl;
    }
};

class AssignOperation : public Operation {
  public:
    AssignOperation() {}
    virtual Operation *Clone() {
      Operation *o = new AssignOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      std::cout << "assign: ";
      Token &tok1 = params.at(0);
      Token &tok2 = params.at(1);
      std::cout << tok1.GetVariable()->GetName() << " = " << tok2.ToString() << std::endl;
      tok1.GetVariable()->SetData(*tok2.GetData());
    }
};

class OutOperation : public Operation {
  public:
    OutOperation() {}
    virtual Operation *Clone() {
      return new OutOperation();
    }
    virtual void Execute(int &prog_counter) {
      // TODO write to file
      std::cout << "out: ";
      for (auto it = params.begin(); it != params.end(); ++it) {
        std::cout << it->ToString() << " ";
      }
      std::cout << std::endl;
    }
};

class SubOperation : public Operation {
  public:
    SubOperation() {}

    virtual Operation *Clone() {
      SubOperation *o = new SubOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      std::cout << "sub: ";
      Token dest_tok = params.front();

      double ddiff = 0.0;
      long ldiff = 0;

      Token tok1 = params[1];
      Token tok2 = params[2];

      if (tok1.IsNumeric()) {
        ddiff = tok1.GetAsNumeric();
        ldiff = tok1.GetAsNumeric();
      } else {
        ddiff = tok1.GetAsReal();
        ldiff = tok1.GetAsReal();
      }

      if (tok2.IsNumeric()) {
        ddiff -= tok2.GetAsNumeric();
        ldiff -= tok2.GetAsNumeric();
      } else {
        ddiff -= tok2.GetAsReal();
        ldiff -= tok2.GetAsReal();
      }

      std::cout << tok1.ToString() << " - " << tok2.ToString();

      Data data;
      if (dest_tok.IsNumeric()) {
        data = Data(ddiff);
      }
      if (dest_tok.IsReal()) {
        data = Data(ldiff);
      }

      dest_tok.SetVariableData(data);
      std::cout << " = " << dest_tok.ToString() << std::endl;
    }
};

#endif
