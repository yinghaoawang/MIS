#ifndef TOKEN_H_
#define TOKEN_H_

#include "IDataHandler.h"
#include "Data.h"
#include "Variable.h"
#include "Label.h"

class Token : public IDataHandler{
  private:
    Data *data;
    Variable *v;
    Label *l;

  public:
    Token(double);
    Token(long);
    Token(char);
    Token(const char*, int);
    Token(Variable* const);
    Token(Label* const);

    bool IsLabel() const;
    bool IsVariable() const;

    void SetVariableData(const Data&);
    Label *GetLabel() const;

    Variable *GetVariable() const;

    Data *GetData() const;
    Data::Type GetType() const;

    bool IsNumeric() const;
    bool IsReal() const;
    bool IsChar() const;
    bool IsString() const;
    bool IsNumber() const;
    bool IsCharSequence() const;

    long GetAsReal() const;
    double GetAsNumeric() const;
    char GetAsChar() const;
    char *GetAsString() const;
};

#endif
