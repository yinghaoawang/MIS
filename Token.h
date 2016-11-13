#ifndef TOKEN_H_
#define TOKEN_H_

#include "Data.h"
#include "Variable.h"
#include "Label.h"

class Token {
  private:
    Data *data;
    Variable *v;
    Label *l;

  public:
    Token(double);
    Token(long);
    Token(char);
    Token(char*, int);
    Token(Variable*);
    Token(Label*);

    Label *GetLabel();
    bool IsLabel();

    Variable *GetVariable();
    bool IsVariable();
    void SetVariableData(Data&);

    Data *GetData();
    Data::Type GetType();

    bool IsNumeric();
    bool IsReal();
    bool IsChar();
    bool IsString();
    bool IsNumber();
    bool IsCharSequence();

    long GetAsReal();
    double GetAsNumeric();
    char GetAsChar();
    char *GetAsString();
};

#endif
