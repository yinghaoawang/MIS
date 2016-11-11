#ifndef DATA_H_
#define DATA_H_

#include <cstring>

class Data {
  private:
    char* str;

  public:
    enum class Type {
      Numeric, Real, Label, Char, String
    };

    union Value {
      double d;
      long l;
      char c;
      char *s;
    };

    Type type;
    Value value;

    Data(double d) { type = Type::Numeric; value.d = d; }
    Data(long l) { type = Type::Real; value.l = l; }
    Data(char c) { type = Type::Char; value.c = c; }
    Data(char *s) {
      type = Type::String;
      value.s = str;
      str = (char*)malloc(sizeof(char) * strlen(s) + 1);
      strcpy(str, s);
    }

    ~Data() {
      if (type == Type::String) free(str);
    }

    double GetNumericValue() { return value.d; }
    long GetRealValue() { return value.l; }
    char GetChar() { return value.c; }
    char *GetString() { return value.s; }
};

#endif
