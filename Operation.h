#ifndef OPERATION_H_
#define OPERATION_H_
#include <iostream>

class Operation {
  public:
    virtual void initialize()=0;
    virtual Operation* clone()=0;
    virtual void execute()=0;
};

class AddOperation : public Operation {
  public:
    AddOperation() {}
    virtual void initialize() {
      // TODO
    }
    virtual Operation* clone() {
      AddOperation *o = new AddOperation();
      o->initialize();
      return o;
    }
    virtual void execute() {
      // TODO
      std::cout << "this is an add operation" << std::endl;
    }
};

class SubOperation : public Operation {
  public:
    SubOperation() {}
    virtual void initialize() {
      // TODO
    }
    virtual Operation* clone() {
      SubOperation *o = new SubOperation();
      o->initialize();
      return o;
    }
    virtual void execute() {
      // TODO
      std::cout << "this is not an add operation OH NO" << std::endl;
    }
};

#endif
