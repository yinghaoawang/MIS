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

class JmpltOperation : public Operation {
  public:
    JmpltOperation() {}
    virtual Operation *Clone() {
      return  new JmpltOperation();
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      Token t3 = params[2];
      bool do_jump = false;
      double d2;
      double d3;
      long l2;
      long l3;
      if (t2.IsNumeric()) {
        d2 = t2.GetAsNumeric();
        l2 = t2.GetAsNumeric();
      } else {
        d2 = t2.GetAsReal();
        l2 = t2.GetAsReal();
      }
      if (t3.IsNumeric()) {
        d3 = t3.GetAsNumeric();
        l3 = t3.GetAsNumeric();
      } else {
        d3 = t3.GetAsReal();
        l3 = t3.GetAsReal();
      }

      if (t2.IsNumeric() && t3.IsNumeric() && d2 < d3) do_jump = true;
      else if (t2.IsNumeric() && t3.IsReal() && d2 < l3) do_jump = true;
      else if (t2.IsReal() && t3.IsNumeric() && l2 < d3) do_jump = true;
      else if (t2.IsReal() && t3.IsReal() && l2 < l3) do_jump = true;

      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmplt: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmplt: not jumping " << t2.ToString() << "!<" << t3.ToString() << std::endl;
      }
    }
};

class JmplteOperation : public Operation {
  public:
    JmplteOperation() {}
    virtual Operation *Clone() {
      return  new JmplteOperation();
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      Token t3 = params[2];
      bool do_jump = false;
      double d2;
      double d3;
      long l2;
      long l3;
      if (t2.IsNumeric()) {
        d2 = t2.GetAsNumeric();
        l2 = t2.GetAsNumeric();
      } else {
        d2 = t2.GetAsReal();
        l2 = t2.GetAsReal();
      }
      if (t3.IsNumeric()) {
        d3 = t3.GetAsNumeric();
        l3 = t3.GetAsNumeric();
      } else {
        d3 = t3.GetAsReal();
        l3 = t3.GetAsReal();
      }

      if (t2.IsNumeric() && t3.IsNumeric() && d2 <= d3) do_jump = true;
      else if (t2.IsNumeric() && t3.IsReal() && d2 <= l3) do_jump = true;
      else if (t2.IsReal() && t3.IsNumeric() && l2 <= d3) do_jump = true;
      else if (t2.IsReal() && t3.IsReal() && l2 <= l3) do_jump = true;

      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmplte: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmplte: not jumping " << t2.ToString() << "!<=" << t3.ToString() << std::endl;
      }
    }
};

class JmpgteOperation : public Operation {
  public:
    JmpgteOperation() {}
    virtual Operation *Clone() {
      return  new JmpgteOperation();
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      Token t3 = params[2];
      bool do_jump = false;
      double d2;
      double d3;
      long l2;
      long l3;
      if (t2.IsNumeric()) {
        d2 = t2.GetAsNumeric();
        l2 = t2.GetAsNumeric();
      } else {
        d2 = t2.GetAsReal();
        l2 = t2.GetAsReal();
      }
      if (t3.IsNumeric()) {
        d3 = t3.GetAsNumeric();
        l3 = t3.GetAsNumeric();
      } else {
        d3 = t3.GetAsReal();
        l3 = t3.GetAsReal();
      }

      if (t2.IsNumeric() && t3.IsNumeric() && d2 >= d3) do_jump = true;
      else if (t2.IsNumeric() && t3.IsReal() && d2 >= l3) do_jump = true;
      else if (t2.IsReal() && t3.IsNumeric() && l2 >= d3) do_jump = true;
      else if (t2.IsReal() && t3.IsReal() && l2 >= l3) do_jump = true;

      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmpgte: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmpgte: not jumping " << t2.ToString() << "!>=" << t3.ToString() << std::endl;
      }
    }
};

class JmpgtOperation : public Operation {
  public:
    JmpgtOperation() {}
    virtual Operation *Clone() {
      return  new JmpgtOperation();
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      Token t3 = params[2];
      bool do_jump = false;
      double d2;
      double d3;
      long l2;
      long l3;
      if (t2.IsNumeric()) {
        d2 = t2.GetAsNumeric();
        l2 = t2.GetAsNumeric();
      } else {
        d2 = t2.GetAsReal();
        l2 = t2.GetAsReal();
      }
      if (t3.IsNumeric()) {
        d3 = t3.GetAsNumeric();
        l3 = t3.GetAsNumeric();
      } else {
        d3 = t3.GetAsReal();
        l3 = t3.GetAsReal();
      }

      if (t2.IsNumeric() && t3.IsNumeric() && d2 > d3) do_jump = true;
      else if (t2.IsNumeric() && t3.IsReal() && d2 > l3) do_jump = true;
      else if (t2.IsReal() && t3.IsNumeric() && l2 > d3) do_jump = true;
      else if (t2.IsReal() && t3.IsReal() && l2 > l3) do_jump = true;

      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmpgt: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmpgt: not jumping" << t2.ToString() << "!>" << t3.ToString() << std::endl;
      }
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
        std::cout << "jmp: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      }
    }
};
class JmpzOperation : public Operation {
  public:
    JmpzOperation() {}
    virtual Operation *Clone() {
      JmpzOperation *o = new JmpzOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      bool do_jump = false;
      if (t2.IsNumeric() && double_equals(t2.GetAsNumeric(), 0)) do_jump = true;
      if (t2.IsReal() && t2.GetAsReal() == 0) do_jump = true;
      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmpz: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmpz: not jumping because " << t2.ToString() << " is not zero" << std::endl;
      }
    }
};

class JmpnzOperation : public Operation {
  public:
    JmpnzOperation() {}
    virtual Operation *Clone() {
      JmpnzOperation *o = new JmpnzOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      Label *l = params.front().GetLabel();
      Token t2 = params[1];
      bool do_jump = false;
      if (t2.IsNumeric() && !double_equals(t2.GetAsNumeric(), 0.0)) do_jump = true;
      if (t2.IsReal() && t2.GetAsReal() != 0) do_jump = true;
      if (l->GetIndex() >= 0 && do_jump == true) {
        std::cout << "jmpnz: " << l->GetName() << ": " << prog_counter << " to " << l->GetIndex() << std::endl;
        prog_counter = l->GetIndex();
      } else {
        std::cout << "jmpnz: not jumping because " << t2.ToString() << " is zero" << std::endl;
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

class MulOperation : public Operation {
  public:
    MulOperation() {}

    virtual Operation* Clone() {
      MulOperation *o = new MulOperation();
      return o;
    }

    virtual void Execute(int &prog_counter) {
      std::cout << "mul: ";
      double dsum = 0.0;
      long lsum = 0;
      Token dest_tok = params.front();
      for (auto it = params.begin(); it != params.end(); ++it) {
        if (it == params.begin()) continue;
        if (it != params.begin() + 1) std::cout << "* "; // DEBUG
        if (it->IsNumeric()) {
          std::cout << it->GetAsNumeric() << " "; // DEBUG
          dsum *= it->GetAsNumeric();
          lsum *= it->GetAsNumeric();
          if (it == params.begin() + 2) {
            dsum = it->GetAsNumeric();
            lsum = it->GetAsNumeric();
          }
        } else if (it->IsReal()) {
        std::cout << it->GetAsReal() << " "; // DEBUG
          dsum *= it->GetAsReal();
          lsum *= it->GetAsReal();
          if (it == params.begin() + 2) {
            dsum = it->GetAsReal();
            lsum = it->GetAsReal();
          }
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

class DivOperation : public Operation {
  public:
    DivOperation() {}

    virtual Operation *Clone() {
      DivOperation *o = new DivOperation();
      return o;
    }
    virtual void Execute(int &prog_counter) {
      std::cout << "div: ";
      Token dest_tok = params.front();

      double ddiff = 0.0;
      long ldiff = 0;
      bool div_by_zero = false;

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
        if (double_equals(tok2.GetAsNumeric(), 0)) {
          div_by_zero = true;
        } else {
          ddiff /= tok2.GetAsNumeric();
          ldiff /= tok2.GetAsNumeric();
        }
      } else {
        if (tok2.GetAsReal() == 0) {
          div_by_zero = true;
        } else {
          ddiff /= tok2.GetAsReal();
          ldiff /= tok2.GetAsReal();
        }
      }

      std::cout << tok1.ToString() << " / " << tok2.ToString();

      if (div_by_zero) {
        std::cout << std::endl;
        std::string str_err = "cannot divide by zero";
        throw std::runtime_error(str_err);
      }
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
