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
    Token(double d) { v = nullptr; l = nullptr; data = new Data(d); }
    Token(long lo) { v = nullptr; l = nullptr; data = new Data(lo); }
    Token(char c) { v = nullptr; l = nullptr; data = new Data(c); }
    Token(char *s) { v = nullptr; l = nullptr; data = new Data(s); }
    Token(Variable *v) {
      l = nullptr;
      this->v = v;
      data = v->GetData();
    }
    Token(Label *l) {
      v = nullptr;
      this->l = l;
    }

    bool IsVariable() {
      return v != nullptr;
    }

    Data *GetData() {
      return data;
    };

    Data::Type GetType() {
      return data->GetType();
    }

    bool IsNumeric() {
      return GetType() == Data::Type::Numeric;
    }
    bool IsReal() {
      return GetType() == Data::Type::Real;
    }
    bool IsChar() {
      return GetType() == Data::Type::Char;
    }
    bool IsString() {
      return GetType() == Data::Type::String;
    }
    bool IsNumber() {
      return GetType() == Data::Type::Numeric || GetType() == Data::Type::Real;
    }
    bool IsCharSequence() {
      return GetType() == Data::Type::Char || GetType() == Data::Type::String;
    }

    long GetRealValue() {
      if (IsVariable()) {
        return (v->GetData())->GetRealValue();
      }
      return data->GetRealValue();
    }

    double GetNumericValue() {
      if (IsVariable()) {
        return (v->GetData())->GetNumericValue();
      }
      return data->GetNumericValue();
    }

    char GetChar() {
      if (IsVariable()) {
        return (v->GetData())->GetChar();
      }
      return (data)->GetChar();
    }

    char *GetString() {
      if (IsVariable()) {
        return (v->GetData())->GetString();
      }
      return data->GetString();
    }

};

#endif
