#ifndef CACHE_H_
#define CACHE_H_

#include <vector>
#include <map>
#include <exception>
#include "Operation.h"
#include "Variable.h"
#include "Label.h"
class Cache {
  public:
    std::vector<Operation*> operations;
    std::map<std::string, Variable*> variables;
    std::map<std::string, Label*> labels;
    Operation *GetOperation(int i) { return operations.at(i); }
    bool CheckLabelValidity() {
      for (auto it = labels.begin(); it != labels.end(); ++it) {
        if (!it->second->HasValidIndex()) {
          std::string str_err = "jump to non declared label: " + it->first;
          throw std::runtime_error(str_err);
        }
      }
      return true;
    }
    int GetOperationSize() { return operations.size(); }
    bool HasVariable(std::string str) {
      if (variables.find(str) == variables.end()) return false;
      return true;
    }
    bool HasVariable(Variable *v) {
      return HasVariable(v->GetName());
    }
    Variable *GetVariable(std::string str) {
      if (!HasVariable(str)) return nullptr;
      return variables[str];
    }
    void SetVariable(Variable *v) {
      if (HasVariable(v)) {
        std::string str_err = "variable already created: " + std::string(v->GetName());
        throw std::runtime_error(str_err);
      }
      variables[v->GetName()] = v;
    }
    bool HasLabel(std::string str) {
      if (labels.find(str) == labels.end()) return false;
      return true;
    }
    bool HasLabel(Label *l) {
      return HasLabel(l->GetName());
    }
    Label *GetLabel(std::string str) {
      if (!HasLabel(str)) return nullptr;
      return labels[str];
    }
    void SetLabel(Label *l) {
      if (HasLabel(l)) {
        std::string str_err = "label already created: " + std::string(l->GetName());
        throw std::runtime_error(str_err);
      }
      labels[l->GetName()] = l;
    }
};

#endif
