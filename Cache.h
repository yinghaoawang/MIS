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
    void *SetVariable(Variable *v) {
      if (HasVariable(v)) {
        std::string str_err = "variable already created: " + std::string(v->GetName());
        throw std::runtime_error(str_err);
      }
      variables[v->GetName()] = v;
    }
};

#endif
