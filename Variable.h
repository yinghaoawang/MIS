#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"

class Variable {
  private:
    Data *data;

  public:
    Variable(Data d) {
      data = (Data*)malloc(sizeof(Data));
      memcpy(data, new Data(d), sizeof(Data));
    }
    ~Variable() { free(data); }
    Data *GetData() { return data; }
};



#endif
