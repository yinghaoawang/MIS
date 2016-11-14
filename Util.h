#ifndef UTIL_H_
#define UTIL_H_

#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

/*
 * Function: cut_quotes
 * Description: Removes first and last char from string
 */
static inline std::string &cut_quotes(std::string &str) {
  str.pop_back();
  str.erase(str.begin());
  return str;
}

/*
 * Function: remove_vector_front
 * Description: removes first element of vector
 */
static inline void remove_vector_front(std::vector<auto> &vec) {
  if (vec.empty()) return;
  vec.erase(vec.begin());
}

/*
 * Function: ltrim
 * Description: trims whitespace from front of string
 */
static inline std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

/*
 * Function: rtrim
 * Description: trims whitespace from end of string
 */
static inline std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

/*
 * Function: trim
 * Description: trims whitespace from string
 */
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}

/*
 * Function: str_is_char
 * Description: if string is formatted like 'c'
 */
static inline bool str_is_char(const std::string &str) {
  if (str.size() != 3) return false;
  if (str[0] != '\'') return false;
  if (str[2] != '\'') return false;
  if (!isalnum(str[1])) return false;
  return true;
}

/*
 * Function: str_is_label
 * Description: if string is formatted like lAbEl1
 */
static inline bool str_is_label(const std::string &str) {
  if (str.size() < 1) return false;
  if (!isalpha(str[0])) return false;
  for (int i = 0; i < str.size(); ++i) {
    if (!isalnum(str[i])) return false;
  }
  return true;
}

/*
 * Function: str_is_string
 * Description: if string is formatted like "sTrInG1"
 */
static inline bool str_is_string(const std::string &str) {
  if (str[0] != '\"') return false;
  if (str[str.size()-1] != '\"') return false;
  for (int i = 1; i < str.size() - 1; ++i) {
    if (!isalpha(str[i])) return false;
  }
  return true;
}

/*
 * Function: str_is_real
 * Description: if string is formatted like 54
 */
static inline bool str_is_real(const std::string &str) {
  for (int i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) return false;
  }
  return true;
}

/*
 * Function: str_is_numeric
 * Description: if string is formatted like 12.45
 */
static inline bool str_is_numeric(const std::string &str) {
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

/*
 * Function: str_is_variable
 * Description: if string is formatted like $mYvAr1
 */
static inline bool str_is_variable(const std::string &str) {
  if (str.size() < 2) return false;
  if (str[0] != '$') return false;
  if (!isalpha(str[1])) return false;
  for (int i = 2; i < str.size(); ++i) {
    if (!isalnum(str[i] )) return false;
  }
  return true;
}

/*
 * Function: get_opname_line
 * Description: advances is to next line, stores first token into src_str, stores read line into src_line
 */
static inline std::istream &get_opname_line(std::istream &is, std::string &src_str, std::string &src_line) {
  std::getline(is, src_line);
  if (trim(src_line).empty()) {
    src_str = "";
    return is;
  }
  char *cstr = (char*)malloc(sizeof(char) * src_line.length() + 1);
  strcpy(cstr, src_line.c_str());
  char *token = std::strtok(cstr, " \n");
  src_str = std::string(token);
  free(cstr);
  return is;
}

/*
 * Function: split_line
 * Description: splits string into tokens delimited by whitespace, returns vector of the string tokens
 */
static inline std::vector<std::string> split_line(const std::string &str) {
  std::vector<std::string> strings;
  char *cstr = (char*)malloc(sizeof(char) * str.length() + 1);
  strcpy(cstr, str.c_str());
  char delims[] = " ,\n\t\r\v\f";
  char* tok_p = strtok(cstr, delims);
  while (tok_p != NULL) {
    strings.push_back(std::string(tok_p));
    tok_p = strtok(NULL, delims);
  }
  free(cstr);
  return strings;
}

#endif
