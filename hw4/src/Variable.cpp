#include "Variable.h"
#include <iostream>

/* VARIABLE
 *
 * A variable has a string name, and a piece of data, a vector of variables
 * are stored in the cache. The variables are modified in the cache during
 * parse (creation of the variables), and execution of the operations
 * (setting and getting of the variables) */

// Straightford constructors, destructors, setters, and getters
Variable::Variable(const std::string &str_name, const Data &d) {
  name = new char[str_name.size() + 1];
  strcpy(name, str_name.c_str());
  data = new Data(d);
}
Variable::~Variable() {
  delete data;
  delete name;
}
char *Variable::GetName() const {
  return name;
}
void Variable::SetData(const Data &d) {
  delete data;
  data = new Data(d);
}
Data *Variable::GetData() const { return data; }
Data::Type Variable::GetType() const { return data->GetType(); }

std::string Variable::ToString() const {
  return data->ToString();
}
size_t Variable::GetStrMaxSize() const {
  if (!IsString()) return 0;
  return data->GetStrMaxSize();
}

bool Variable::IsNumeric() const {
  return data->IsNumeric();
}
bool Variable::IsReal() const {
  return data->IsReal();
}
bool Variable::IsChar() const {
  return data->IsChar();
}
bool Variable::IsString() const {
  return data->IsString();
}
bool Variable::IsNumber() const {
  return data->IsNumber();
}
bool Variable::IsCharSequence() const {
  return data->IsCharSequence();
}

long Variable::GetAsReal() const {
  return data->GetAsReal();
}
double Variable::GetAsNumeric() const {
  return data->GetAsNumeric();
}
char Variable::GetAsChar() const {
  return data->GetAsChar();
}
char *Variable::GetAsString() const {
  return data->GetAsString();
}
