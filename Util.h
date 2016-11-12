#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <string>
#include <cstring>
#include <sstream>

/* get's the operation name of the next line in input stream
 * i.e ADD $var, 1, 2
 * sets src_str to "ADD"
 */
inline std::istream &get_opname_line(std::istream &is, std::string &src_str, std::string &src_line) {
  // TODO - not optimized
  std::string str;
  std::getline(is, str);
  if (str.empty()) return is;
  if (src_line.empty()) src_line = str;
  char *cstr = (char*)malloc(sizeof(char) * str.length() + 1);
  strcpy(cstr, str.c_str());
  char *token = std::strtok(cstr, " \n");
  src_str = std::string(token);
  free(cstr);
  return is;
}

/* pass in a string instead of is */
inline std::istream &get_opname_line(std::string &is_str, std::string &src_str, std::string &src_line) {
  // TODO - not optimized
  std::istringstream iss(is_str);
  return get_opname_line(iss, src_str, src_line);
}

/* gets operation name from line */
inline std::istream &get_opname_line(std::string &is_str, std::string &src_str) {
  // TODO - not optimized
  std::string str_line = std::string("");
  return get_opname_line(is_str, src_str, str_line);
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

