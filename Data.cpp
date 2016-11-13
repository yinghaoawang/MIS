#include "Data.h"
#include <cstdlib>

Data::Data() {}
Data::Data(Data const &data) {
  type = data.type;
  value = data.value;
}
Data::Data(double d) { type = Type::Numeric; value.d = d; }
Data::Data(long l) { type = Type::Real; value.l = l; }
Data::Data(char c) { type = Type::Char; value.c = c; }
Data::Data(char *s, int size) {
  type = Type::String;
  value.s = str;
  str = (char*)malloc(sizeof(char) * size);
  strcpy(str, s);
}
Data::Data(const std::string &str, int size) {
  char *s = (char*)malloc(sizeof(char) * size);
  value.s = this->str;
}

Data::Type Data::GetType() const {
  return type;
}
Data::Value Data::GetValue() const {
  return value;
}

Data::~Data() {
  if (type == Type::String) free(str);
}

double Data::GetAsNumeric() const { return value.d; }
long Data::GetAsReal() const { return value.l; }
char Data::GetAsChar() const { return value.c; }
char *Data::GetAsString() const { return value.s; }
