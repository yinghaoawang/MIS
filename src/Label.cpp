#include "Label.h"
#include <cstring>

// Constructor
Label::Label(const std::string &str_name, int i) {
  name = new char[str_name.size() + 1];
  strcpy(name, str_name.c_str());
  index = i;
}

// Destructor
Label::~Label() { delete name; }

// Setters and getts
char *Label::GetName() const { return name; }
bool Label::HasValidIndex() const {
  return index >= 0;
}
void Label::SetIndex(int i) {
  index = i;
}
int Label::GetIndex() const { return index; }
