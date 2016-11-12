#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"

class Variable {
  private:
    Data *data;

  public:
    Variable(Data d) {
      Init(d);
    }
    void Init(Data d) {
      data = (Data*)malloc(sizeof(Data));
      data = new Data(d);
    }
    ~Variable() { free(data); }
    void SetData(Data &d) {
      delete data;
      Init(d);
    }
    Data *GetData() { return data; }
};



#endif
