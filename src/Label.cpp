#include "Label.h"
#include <cstring>

Label::Label(const std::string &str_name, int i) {
  name = new char[str_name.size() + 1];
  strcpy(name, str_name.c_str());
  Init(i);
}
Label::~Label() { delete name; }
char *Label::GetName() const { return name; }
void Label::Init(int i) {
  index = i;
}
bool Label::HasValidIndex() const {
  return index >= 0;
}
void Label::SetIndex(int i) {
  Init(i);
}
int Label::GetIndex() const { return index; }
