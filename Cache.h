#ifndef CACHE_H_
#define CACHE_H_

#include <vector>
#include <map>
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
    Variable *GetVariable(std::string str) {
      if (!HasVariable(str)) return nullptr;
      return variables[str];
    }
};

#endif
