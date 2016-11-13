#include "Token.h"

Token::Token(double d) { v = nullptr; l = nullptr; data = new Data(d); }
Token::Token(long lo) { v = nullptr; l = nullptr; data = new Data(lo); }
Token::Token(char c) { v = nullptr; l = nullptr; data = new Data(c); }
Token::Token(char *s, int size) { v = nullptr; l = nullptr; data = new Data(s, size); }
Token::Token(Variable *v) {
  l = nullptr;
  this->v = v;
  data = v->GetData();
}
Token::Token(Label *l) {
  v = nullptr;
  this->l = l;
}

Label *Token::GetLabel() {
  return l;
}

Variable *Token::GetVariable() {
  return v;
}

bool Token::IsLabel() {
  return v != nullptr;
}

bool Token::IsVariable() {
  return v != nullptr;
}

void Token::SetVariableData(Data &d) {
  if (!IsVariable()) return;
  v->SetData(d);
}

Data *Token::GetData() {
  return data;
};

Data::Type Token::GetType() {
  return data->GetType();
}

bool Token::IsNumeric() {
  return GetType() == Data::Type::Numeric;
}
bool Token::IsReal() {
  return GetType() == Data::Type::Real;
}
bool Token::IsChar() {
  return GetType() == Data::Type::Char;
}
bool Token::IsString() {
  return GetType() == Data::Type::String;
}
bool Token::IsNumber() {
  return GetType() == Data::Type::Numeric || GetType() == Data::Type::Real;
}
bool Token::IsCharSequence() {
  return GetType() == Data::Type::Char || GetType() == Data::Type::String;
}

long Token::GetAsReal() {
  if (v != nullptr) {
    return (v->GetData())->GetAsReal();
  }
  return (data)->GetAsReal();
}

double Token::GetAsNumeric() {
  if (v != nullptr) {
    return (v->GetData())->GetAsNumeric();
  }
  return (data)->GetAsNumeric();
}

char Token::GetAsChar() {
  if (v != nullptr) {
    return (v->GetData())->GetAsChar();
  }
  return (data)->GetAsChar();
}

char *Token::GetAsString() {
  if (v != nullptr) {
    return (v->GetData())->GetAsString();
  }
  return (data)->GetAsString();
}
