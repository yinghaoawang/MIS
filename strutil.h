#include <vector>
#include <string>

std::vector<std::string> split_line(std::string &str) {
  // TODO - super ineffish, completely ineffish, cpp is too hard
  std::vector<std::string> strings;
  char *cstr = (char*)malloc(sizeof(char) * str.length() + 1);
  strcpy(cstr, str.c_str());
  char* pch = strtok(cstr, " ,\n");
  while (pch != NULL) {
    strings.push_back(std::string(pch));
    pch = strtok(NULL, " ,\n");
  }
  free(cstr);
  return strings;
}
