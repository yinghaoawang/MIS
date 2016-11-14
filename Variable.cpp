#include "Variable.h"

Variable::Variable(const std::string &str_name, const Data &d) {
  name = new char[str_name.size() + 1];
  strcpy(name, str_name.c_str());
  Init(d);
}
Variable::~Variable() {
  delete data;
  delete name;
}
char *Variable::GetName() const {
  return name;
}
void Variable::Init(const Data &d) {
  data = new Data(d);
}
void Variable::SetData(const Data &d) {
  delete data;
  Init(d);
}
Data *Variable::GetData() const { return data; }

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
