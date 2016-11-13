#ifndef UTIL_H_
#define UTIL_H_

#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

/* remove front of vector */
inline void remove_vector_front(std::vector<auto> &vec) {
  if (vec.empty()) return;
  vec.erase(vec.begin());
}

// trim from start
static inline std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}

/* i.e LABEL1, Label1, a1l2b3 */
inline bool str_is_label(std::string const &str) {
  for (int i = 0; i < str.size(); ++i) {
    if (i == 0) {
      if (!isalpha(str[i])) return false;
    } else {
      if (!isalpha(str[i])) return false;
    }
  }
  return true;
}

/* i.e 132.2, 0.0, 3.1416 */
inline bool str_is_real(std::string const &str) {
  for (int i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) return false;
  }
  return true;
}

/* i.e 123, 0, 1.5 */
inline bool str_is_numeric(std::string const &str) {
  int period_count = 0;
  for (int i = 0 ; i < str.size(); ++i) {
    if (str[i] == '.') {
      ++period_count;
    } else if (!isdigit(str[i])) {
      return false;
    }
  }
  if (period_count != 1) return false;
  return true;
}

/* i.e $mystr, $STRING, $a1s2T9 */
inline bool str_is_variable(std::string const &str) {
  if (str[0] != '$') return false;
  if (str.size() < 2) return false;
  for (int i = 1; i < str.size(); ++i) {
    if (!isalnum(str[i])) return false;
  }
  return true;
}

/* get's the operation name of the next line in input stream
 * i.e ADD $var, 1, 2
 * sets src_str to "ADD"
 */
inline std::istream &get_opname_line(std::istream &is, std::string &src_str, std::string &src_line) {
  // TODO - not optimized
  std::string str;
  std::getline(is, str);
  if (trim(str).empty()) {
    src_str = "";
    return is;
  }
  src_line = str;
  char *cstr = (char*)malloc(sizeof(char) * str.length() + 1);
  strcpy(cstr, str.c_str());
  char *token = std::strtok(cstr, " \n");
  src_str = std::string(token);
  free(cstr);
  return is;
}

inline std::vector<std::string> split_line(std::string const &str) {
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

