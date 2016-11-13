#ifndef CACHE_H_
#define CACHE_H_

#include <vector>
#include <map>
#include "Operation.h"
#include "Variable.h"
#include "Label.h"

class Cache {
  private:
    std::vector<Operation*> operations;
    std::map<std::string, Variable*> variables;
    std::map<std::string, Label*> labels;
  public:
    Operation *GetOperation(int);
    void PushOperation(Operation*);
    int GetOperationSize();

    int GetVariableSize();
    bool HasVariable(std::string&);
    bool HasVariable(Variable*);
    Variable *GetVariable(std::string&);
    void SetVariable(Variable *V);

    int GetLabelSize();
    bool HasLabel(std::string&);
    bool HasLabel(Label*);
    Label *GetLabel(std::string&);
    void SetLabel(Label*);

    bool CheckLabelValidity();
};

#endif
