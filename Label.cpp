#include "Label.h"
#include <cstring>

Label::Label(std::string &str_name, int i) {
  name = (char*)malloc(sizeof(char) * str_name.size() + 1);
  strcpy(name, str_name.c_str());
  Init(i);
}
Label::~Label() { free(name); }
char *Label::GetName() { return name; }
void Label::Init(int i) {
  index = i;
}
bool Label::HasValidIndex() {
  return index >= 0;
}
void Label::SetIndex(int i) {
  Init(i);
}
int Label::GetIndex() { return index; }
