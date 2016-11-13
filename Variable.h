#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Data.h"
#include <string>

class Variable {
  private:
    Data *data;
    char *name;

  public:
    Variable(const std::string&, const Data&);
    ~Variable();
    char *GetName() const;
    void Init(const Data&);
    void SetData(const Data&);
    Data *GetData() const;
};
#endif
