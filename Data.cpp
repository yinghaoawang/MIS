#include "Data.h"
#include "Util.h"
#include <cstdlib>

Data::Data() {}
Data::Data(Data const &data) {
  type = data.type;
  value = data.value;
}
Data::Data(double d) { type = Type::Numeric; value.d = d; }
Data::Data(long l) { type = Type::Real; value.l = l; }
Data::Data(char c) { type = Type::Char; value.c = c; }
Data::Data(char *src_str, size_t size) {
  type = Type::String;
  str = new char[size + 1];
  strcpy(str, src_str);
  value.s = str;
}
Data::Data(const std::string &src_str, size_t size) {
  type = Type::String;
  str = new char[size + 1];
  strcpy(str, src_str.c_str());
  value.s = str;
}

Data::Type Data::GetType() const {
  return type;
}
Data::Value Data::GetValue() const {
  return value;
}

std::string Data::ToString() const {
  std::string str;
  if (IsNumeric()) {
    str = std::to_string(GetAsNumeric());
    remove_trailing_zeroes(str);
  } else if (IsReal()) {
    str = std::to_string(GetAsReal());
  } else if (IsChar()) {
    str = std::to_string(GetAsChar());
  } else if (IsString()) {
    str = GetAsString();
  } else {
    str = nullptr;
  }

  return str;
}

/* TODO this breaks program for some reason
Data::~Data() {
  //if (type == Type::String) delete str;
}
*/

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
