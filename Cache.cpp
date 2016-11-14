#include "Cache.h"
#include <exception>

Operation *Cache::GetOperation(int i) const { return operations.at(i); }
Variable *Cache::GetVariable(const std::string &str) const {
  if (!HasVariable(str)) return nullptr;
  return variables.at(str);
}
Label *Cache::GetLabel(const std::string &str) const {
  if (!HasLabel(str)) return nullptr;
  return labels.at(str);
}
void Cache::SetLabel(Label * const l) {
  if (HasLabel(l)) {
    std::string str_err = "label already created: " + std::string(l->GetName());
    throw std::runtime_error(str_err);
  }
  labels[l->GetName()] = l;
}

int Cache::GetOperationSize() const { return operations.size(); }
int Cache::GetVariableSize() const { return variables.size(); }
int Cache::GetLabelSize() const { return labels.size(); }

void Cache::PushOperation(Operation * const op) {
  operations.push_back(op);
}
void Cache::SetVariable(Variable * const v) {
  if (HasVariable(v)) {
    std::string str_err = "cannot declare, variable already created: " + std::string(v->GetName());
    throw std::runtime_error(str_err);
  }
  variables[v->GetName()] = v;
}
void Cache::SetVariableData(const std::string &varname, const Data &data) {
  if (!HasVariable(varname)) {
    std::string str_err = "cannot set, variable not yet created: " + varname;
    throw std::runtime_error(str_err);
  }
  Variable *v = GetVariable(varname);
  v->SetData(data);
}

bool Cache::HasVariable(const std::string &str) const {
  if (variables.find(str) == variables.end()) return false;
  return true;
}
bool Cache::HasVariable(const Variable * const v) const {
  std::string str = v->GetName();
  return HasVariable(str);
}
bool Cache::HasLabel(const std::string &str) const {
  if (labels.find(str) == labels.end()) return false;
  return true;
}
bool Cache::HasLabel(const Label * const l) const {
  std::string str = l->GetName();
  return HasLabel(str);
}

bool Cache::CheckLabelValidity() const {
  for (auto it = labels.begin(); it != labels.end(); ++it) {
    if (!it->second->HasValidIndex()) {
      std::string str_err = "jump to non declared label: " + it->first;
      throw std::runtime_error(str_err);
    }
  }
  return true;
}
