#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <string>
#include <cstring>

/* get's the operation name of the next line in input stream
 * i.e ADD $var, 1, 2
 * sets src_str to "ADD"
 */
void get_opname_line(std::istream&is, std::string& src_str, std::string& src_line) {
  // TODO - not optimized
  if (src_str.empty()) return;
  std::string str;
  std::getline(is, str);
  if (src_line.empty()) src_line = str;
  char *cstr = (char*)malloc(sizeof(char) * str.length() + 1);
  strcpy(cstr, str.c_str());
  char *token = std::strtok(cstr, " \n");
  src_str = std::string(token);
  free(cstr);
}


inline std::vector<std::string> split_line(std::string &str) {
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

#endif

