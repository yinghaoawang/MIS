#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"

class Variable {
  private:
    Data *data;
    char *name;

  public:
    Variable(std::string &str_name, Data d) {
      name = (char*)malloc(sizeof(char) * str_name.size() + 1);
      strcpy(name, str_name.c_str());
      Init(d);
    }
    ~Variable() {
      free(data);
      free(name);
    }
    char *GetName() {
      return name;
    }
    void Init(Data d) {
      data = (Data*)malloc(sizeof(Data));
      data = new Data(d);
    }
    void SetData(Data &d) {
      delete data;
      Init(d);
    }
    Data *GetData() { return data; }
};



#endif
