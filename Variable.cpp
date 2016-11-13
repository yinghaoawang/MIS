#include "Variable.h"

Variable::Variable(const std::string &str_name, const Data &d) {
  name = (char*)malloc(sizeof(char) * str_name.size() + 1);
  strcpy(name, str_name.c_str());
  Init(d);
}
Variable::~Variable() {
  free(data);
  free(name);
}
char *Variable::GetName() const {
  return name;
}
void Variable::Init(const Data &d) {
  data = (Data*)malloc(sizeof(Data));
  data = new Data(d);
}
void Variable::SetData(const Data &d) {
  delete data;
  Init(d);
}
Data *Variable::GetData() const { return data; }
