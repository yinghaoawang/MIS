#include "Token.h"

Token::Token(double d) { v = nullptr; l = nullptr; data = new Data(d); }
Token::Token(long lo) { v = nullptr; l = nullptr; data = new Data(lo); }
Token::Token(char c) { v = nullptr; l = nullptr; data = new Data(c); }
Token::Token(const char * const s, int size) { v = nullptr; l = nullptr; data = new Data(s, size); }
Token::Token(Variable * const v) {
  l = nullptr;
  this->v = v;
  data = v->GetData();
}
Token::Token(Label * const l) {
  v = nullptr;
  this->l = l;
}

Label *Token::GetLabel() const {
  return l;
}

Variable *Token::GetVariable() const {
  return v;
}

bool Token::IsLabel() const {
  return v != nullptr;
}

bool Token::IsVariable() const {
  return v != nullptr;
}

void Token::SetVariableData(const Data &d) {
  if (!IsVariable()) return;
  v->SetData(d);
}

Data *Token::GetData() const {
  return data;
};

Data::Type Token::GetType() const {
  return data->GetType();
}

bool Token::IsNumeric() const {
  return GetType() == Data::Type::Numeric;
}
bool Token::IsReal() const {
  return GetType() == Data::Type::Real;
}
bool Token::IsChar() const {
  return GetType() == Data::Type::Char;
}
bool Token::IsString() const {
  return GetType() == Data::Type::String;
}
bool Token::IsNumber() const {
  return GetType() == Data::Type::Numeric || GetType() == Data::Type::Real;
}
bool Token::IsCharSequence() const {
  return GetType() == Data::Type::Char || GetType() == Data::Type::String;
}

long Token::GetAsReal() const {
  if (v != nullptr) {
    return (v->GetData())->GetAsReal();
  }
  return (data)->GetAsReal();
}

double Token::GetAsNumeric() const {
  if (v != nullptr) {
    return (v->GetData())->GetAsNumeric();
  }
  return (data)->GetAsNumeric();
}

char Token::GetAsChar() const {
  if (v != nullptr) {
    return (v->GetData())->GetAsChar();
  }
  return (data)->GetAsChar();
}

char *Token::GetAsString() const {
  if (v != nullptr) {
    return (v->GetData())->GetAsString();
  }
  return (data)->GetAsString();
}
