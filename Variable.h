#ifndef VARIABLE_H_
#define VARIABLE_H_

class Variable {
  public:
    std::string name;
};

class CharSequence : Variable {
  public:
    virtual char asChar()=0;
    virtual char* asString()=0;
};

class String : CharSequence {
  private:
    char s[256];
  public:
    char asChar() {
      return s[0];
    }
    char* asString() {
      return s;
    }
};

class Char : CharSequence {
  private:
    char c;
  public:
    char asChar() {
      return c;
    }
    char* asString() {
      return &c;
    }
};

#endif
