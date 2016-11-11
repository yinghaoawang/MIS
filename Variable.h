#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"

class Variable {
  private:
    Data *data;

  public:
    Data *GetData() { return data; }
};



#endif
