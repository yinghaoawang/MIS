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
    friend class TokenManager;
    Token(double d) { data = new Data(d); }
    Token(long l) { data = new Data(l); }
    Token(char c) { data = new Data(c); }
    Token(char *s) { data = new Data(s); }
    Token(Variable *v) {
      this->v = v;
      data = v->GetData();
    }
    Token(Label *l) {
      this->l = l;
    }

    Data *GetData() {
      return data;
    };

};

class TokenManager {
  public:
    long GetRealValue(Token const &tok) {
      if (tok.v != nullptr) {
        return (tok.v->GetData())->GetRealValue();
      }
      return (tok.data)->GetRealValue();
    }

    double GetNumericValue(Token const &tok) {
      if (tok.v != nullptr) {
        return (tok.v->GetData())->GetNumericValue();
      }
      return (tok.data)->GetNumericValue();
    }

    char GetChar(Token const &tok) {
      if (tok.v != nullptr) {
        return (tok.v->GetData())->GetChar();
      }
      return (tok.data)->GetChar();
    }

    char *GetString(Token const &tok) {
      if (tok.v != nullptr) {
        return (tok.v->GetData())->GetString();
      }
      return (tok.data)->GetString();
    }

};

#endif
