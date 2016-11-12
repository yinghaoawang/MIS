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

    void SetVariableData(Data &d) {
      if (!IsVariable()) return;
      v->SetData(d);
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

    long GetAsReal() {
      if (v != nullptr) {
        return (v->GetData())->GetAsReal();
      }
      return (data)->GetAsReal();
    }

    double GetAsNumeric() {
      if (v != nullptr) {
        return (v->GetData())->GetAsNumeric();
      }
      return (data)->GetAsNumeric();
    }

    char GetAsChar() {
      if (v != nullptr) {
        return (v->GetData())->GetAsChar();
      }
      return (data)->GetAsChar();
    }

    char *GetAsString() {
      if (v != nullptr) {
        return (v->GetData())->GetAsString();
      }
      return (data)->GetAsString();
    }
};

#endif
