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
  str = new char[size + 1];
  strcpy(str, s);
}
Data::Data(const std::string &str, int size) {
  char *s = new char[size + 1];
  value.s = this->str;
}

Data::Type Data::GetType() const {
  return type;
}
Data::Value Data::GetValue() const {
  return value;
}

Data::~Data() {
  if (type == Type::String) delete str;
}

double Data::GetAsNumeric() const { return value.d; }
long Data::GetAsReal() const { return value.l; }
char Data::GetAsChar() const { return value.c; }
char *Data::GetAsString() const { return value.s; }

bool Data::IsNumeric() const {
  return GetType() == Data::Type::Numeric;
}
bool Data::IsReal() const {
  return GetType() == Data::Type::Real;
}
bool Data::IsChar() const {
  return GetType() == Data::Type::Char;
}
bool Data::IsString() const {
  return GetType() == Data::Type::String;
}
bool Data::IsNumber() const {
  return IsReal() || IsNumeric();
}
bool Data::IsCharSequence() const {
  return IsChar() || IsString();
}
