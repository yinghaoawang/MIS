#include "Token.h"
#include <iostream>

/* A token is used as the arguments
 * for operations, so a token may be
 * any data, as well as a variable or label */

// Constructors
Token::Token(double d) { v = nullptr; l = nullptr; data = new Data(d); }
Token::Token(long lo) { v = nullptr; l = nullptr; data = new Data(lo); }
Token::Token(char c) { v = nullptr; l = nullptr; data = new Data(c); }
Token::Token(const char * const s, size_t size) { v = nullptr; l = nullptr; data = new Data(s, size); }
Token::Token(const char * const s) { v = nullptr; l = nullptr; data = new Data(s, strlen(s) + 1); }
Token::Token(Variable * const v) { // When given a variable
  l = nullptr;
  this->v = v; // Set the variable to the variable
  data = v->GetData(); // Set the data to the variables data (mainly to ease the checks on the types)
}
Token::Token(Label * const l) {
  v = nullptr;
  this->l = l;
}

// Destructor
Token::~Token() {}

// Getters and setters
Label *Token::GetLabel() const {
  return l;
}

Variable *Token::GetVariable() const {
  return v;
}

bool Token::IsLabel() const {
  return l != nullptr;
}

bool Token::IsVariable() const {
  return v != nullptr;
}

void Token::SetVariableData(const Data &d) {
  if (!IsVariable()) return;
  v->SetData(d);
}

Data *Token::GetData() const {
  if (IsVariable()) return v->GetData();
  return data;
};

Data::Type Token::GetType() const {
  if (IsVariable()) return v->GetType();
  return data->GetType();
}

std::string Token::ToString() const {
  if (IsVariable()) return v->ToString();
  return data->ToString();
}

size_t Token::GetStrMaxSize() const {
  if (IsVariable()) {
    return v->GetStrMaxSize();
  }
  return data->GetStrMaxSize();
}

long Token::GetAsReal() const {
  if (IsVariable()) {
    return (v->GetAsReal());
  }
  return data->GetAsReal();
}

double Token::GetAsNumeric() const {
  if (IsVariable()) {
    return (v->GetAsNumeric());
  }
  return data->GetAsNumeric();
}

char Token::GetAsChar() const {
  if (IsVariable()) {
    return (v->GetAsChar());
  }
  return data->GetAsChar();
}

char *Token::GetAsString() const {
  if (IsVariable()) {
    return (v->GetAsString());
  }
  return data->GetAsString();
}

bool Token::IsNumeric() const {
  if (IsVariable()) return v->IsNumeric();
  return data->IsNumeric();
}
bool Token::IsReal() const {
  if (IsVariable()) return v->IsReal();
  return data->IsReal();
}
bool Token::IsChar() const {
  if (IsVariable()) return v->IsChar();
  return data->IsChar();
}
bool Token::IsString() const {
  if (IsVariable()) return v->IsString();
  return data->IsString();
}
bool Token::IsNumber() const {
  if (IsVariable()) return v->IsNumber();
  return data->IsNumber();
}
bool Token::IsCharSequence() const {
  if (IsVariable()) return v->IsCharSequence();
  return data->IsCharSequence();
}
