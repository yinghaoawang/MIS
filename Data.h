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
    Data(char*, size_t);
    Data(const std::string&, size_t);
    ~Data();

    Type GetType() const;
    Value GetValue() const;

    std::string ToString() const;

    double GetAsNumeric() const;
    long GetAsReal() const;
    char GetAsChar() const;
    char *GetAsString() const;

    bool IsNumeric() const;
    bool IsReal() const;
    bool IsChar() const;
    bool IsString() const;
    bool IsNumber() const;
    bool IsCharSequence() const;
};

#endif
