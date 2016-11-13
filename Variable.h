#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"
#include <string>

class Variable {
  private:
    Data *data;
    char *name;

  public:
    Variable(std::string&, Data&);
    ~Variable();
    char *GetName();
    void Init(Data&);
    void SetData(Data&);
    Data *GetData();
};
#endif
