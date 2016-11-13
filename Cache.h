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
    Operation *GetOperation(int) const;
    void PushOperation(Operation* const);
    int GetOperationSize() const;

    int GetVariableSize() const;
    bool HasVariable(const std::string&) const;
    bool HasVariable(const Variable* const) const;
    Variable *GetVariable(const std::string&) const;
    void SetVariable(Variable* const);

    int GetLabelSize() const;
    bool HasLabel(const std::string&) const;
    bool HasLabel(const Label* const) const;
    Label *GetLabel(const std::string&) const;
    void SetLabel(Label* const);

    bool CheckLabelValidity() const;
};

#endif
