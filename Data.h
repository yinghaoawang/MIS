#ifndef DATA_H_
#define DATA_H_

#include <cstring>

class Data {
  public:
    enum class Type {
      Numeric, Real, Label, Char, String, Any
    };

    union Value {
      double d;
      long l;
      char c;
      char *s;
    };

  private:
    char* str;
    Type type;
    Value value;

  public:
    Data() {}
    Data(Data const &data) {
      type = data.type;
      value = data.value;
    }
    Data(double d) { type = Type::Numeric; value.d = d; }
    Data(long l) { type = Type::Real; value.l = l; }
    Data(char c) { type = Type::Char; value.c = c; }
    Data(char *s, int size) {
      type = Type::String;
      value.s = str;
      str = (char*)malloc(sizeof(char) * size);
      strcpy(str, s);
    }
    Data(std::string str, int size) {
      char *s = (char*)malloc(sizeof(char) * size);
      value.s = this->str;
    }
    Type GetType() {
      return type;
    }
    Value Value() {
      return value;
    }

    ~Data() {
      if (type == Type::String) free(str);
    }

    double GetAsNumeric() { return value.d; }
    long GetAsReal() { return value.l; }
    char GetAsChar() { return value.c; }
    char *GetAsString() { return value.s; }
};

#endif