#ifndef OPERATION_H_
#define OPERATION_H_
#include <iostream>
#include <vector>
#include "Token.h"

class Operation {
  protected:
    int min_params;
    int max_params;
    std::vector<Token> params;
  public:
    virtual void Init()=0;
    virtual Operation* Clone()=0;
    virtual void Execute()=0;
    virtual void SetParams(std::vector<Token> tok) {
      for (auto it = tok.begin(); it != tok.end(); ++it) {
        if (it == tok.begin()) continue; // hardcode of skipping first (instruction name)
        params.push_back(*it);
      }
    }
    int GetMinParams() { return min_params; }
    int GetMaxParams() { return max_params; }
};

class AddOperation : public Operation {
  public:
    AddOperation() {}
    virtual void Init() {
      min_params = 3;
      max_params = 13;
    }
    virtual Operation* Clone() {
      AddOperation *o = new AddOperation();
      o->Init();
      return o;
    }
    virtual void Execute() {
      // TODO
      std::cout << "this is an add operation" << std::endl;
    }
};

class SubOperation : public Operation {
  public:
    SubOperation() {}
    virtual void Init() {
      min_params = 3;
      max_params = 3;
    }
    virtual Operation* Clone() {
      SubOperation *o = new SubOperation();
      o->Init();
      return o;
    }
    virtual void Execute() {
      // TODO
      std::cout << "this is not an add operation OH NO" << std::endl;
    }
};

#endif
