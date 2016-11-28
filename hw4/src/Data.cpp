#include "Data.h"
#include "Util.h"
#include <cstdlib>

/* Constructors, sets type to respective data type, and value to argument */
Data::Data() {}
Data::Data(const Data &data) {
  type = data.type;
  value = data.value;
  if (data.type == Data::Type::String) {
    str_max_size = data.str_max_size;
    str = new char[str_max_size + 1];
    strcpy(str, data.str);
    value.s = str;
  }
}
Data::Data(double d) { type = Type::Numeric; value.d = d; }
Data::Data(long l) { type = Type::Real; value.l = l; }
Data::Data(char c) { type = Type::Char; value.c = c; }
Data::Data(char *src_str, size_t size) { /* The size is the max size of string, not necessarily its current length */
  type = Type::String;
  str = new char[size + 1];
  str_max_size = size;
  strcpy(str, src_str);
  value.s = str;
}
Data::Data(const std::string &src_str, size_t size) {
  type = Type::String;
  str = new char[size + 1];
  str_max_size = size;
  strcpy(str, src_str.c_str());
  value.s = str;
}

Data::Type Data::GetType() const {
  return type;
}

/* Prints out its string formatted value depending on what type it is */
std::string Data::ToString() const {
  std::string str;
  if (IsNumeric()) {
    str = std::to_string(GetAsNumeric());
    remove_trailing_zeroes(str);
  } else if (IsReal()) {
    str = std::to_string(GetAsReal());
  } else if (IsChar()) {
    str = GetAsChar();
  } else if (IsString()) {
    str = GetAsString();
  } else {
    str = nullptr;
  }

  return str;
}

size_t Data::GetStrMaxSize() const {
  if (!IsString()) return 0;
  return str_max_size;
}

Data::~Data() {
  // TODO why crash
  //if (type == Type::String) delete[] str;
}

/* Self explanatory:
 * Gets value in union
 * Returns boolean if its type is the respective type
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
