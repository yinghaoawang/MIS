#include "Cache.h"
#include <exception>

Operation *Cache::GetOperation(int i) { return operations.at(i); }
bool Cache::CheckLabelValidity() {
  for (auto it = labels.begin(); it != labels.end(); ++it) {
    if (!it->second->HasValidIndex()) {
      std::string str_err = "jump to non declared label: " + it->first;
      throw std::runtime_error(str_err);
    }
  }
  return true;
}
int Cache::GetOperationSize() { return operations.size(); }
int Cache::GetVariableSize() { return variables.size(); }
int Cache::GetLabelSize() { return labels.size(); }

void Cache::PushOperation(Operation *op) {
  operations.push_back(op);
}

bool Cache::HasVariable(std::string &str) {
  if (variables.find(str) == variables.end()) return false;
  return true;
}
bool Cache::HasVariable(Variable *v) {
  std::string str = v->GetName();
  return HasVariable(str);
}
Variable *Cache::GetVariable(std::string &str) {
  if (!HasVariable(str)) return nullptr;
  return variables[str];
}
void Cache::SetVariable(Variable *v) {
  if (HasVariable(v)) {
    std::string str_err = "variable already created: " + std::string(v->GetName());
    throw std::runtime_error(str_err);
  }
  variables[v->GetName()] = v;
}
bool Cache::HasLabel(std::string &str) {
  if (labels.find(str) == labels.end()) return false;
  return true;
}
bool Cache::HasLabel(Label *l) {
  std::string str = l->GetName();
  return HasLabel(str);
}
Label *Cache::GetLabel(std::string &str) {
  if (!HasLabel(str)) return nullptr;
  return labels[str];
}
void Cache::SetLabel(Label *l) {
  if (HasLabel(l)) {
    std::string str_err = "label already created: " + std::string(l->GetName());
    throw std::runtime_error(str_err);
  }
  labels[l->GetName()] = l;
}
