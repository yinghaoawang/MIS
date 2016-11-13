#include "Variable.h"

Variable::Variable(std::string &str_name, Data &d) {
  name = (char*)malloc(sizeof(char) * str_name.size() + 1);
  strcpy(name, str_name.c_str());
  Init(d);
}
Variable::~Variable() {
  free(data);
  free(name);
}
char *Variable::GetName() {
  return name;
}
void Variable::Init(Data &d) {
  data = (Data*)malloc(sizeof(Data));
  data = new Data(d);
}
void Variable::SetData(Data &d) {
  delete data;
  Init(d);
}
Data *Variable::GetData() { return data; }
