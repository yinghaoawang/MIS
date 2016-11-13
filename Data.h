#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <cstring>

class Data {
  public:
    enum class Type {
      Numeric, Real, Char, String
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
    Data();
    Data(Data const&);
    Data(double);
    Data(long);
    Data(char);
    Data(char*, int);
    Data(std::string, int);
    ~Data();

    Type GetType();
    Value GetValue();

    double GetAsNumeric();
    long GetAsReal();
    char GetAsChar();
    char *GetAsString();
};

#endif
