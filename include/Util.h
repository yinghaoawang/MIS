#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>
#include <unistd.h>

/*
 * Function: clear_file
 * Description: creates a new file, deletes old one if exists
 */
static inline void clear_file(const char *filename) {
  std::fstream file;
  file.open(filename, std::fstream::out);
  file.close();
}

/*
 * Function: print_out
 * Description: prints output to stdout and writes to filename
 */
static inline void print_out(std::string msg, const char *filename) {
  std::fstream file;
  file.open(filename, std::fstream::app);
  if (!file.is_open()) {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }
  file << msg;
  file.close();
}

/*
 * Function: print_err
 * Description: prints output to stderr and writes to filename
 */
static inline void print_err(std::string msg, const char *filename) {
  std::fstream file;
  file.open(filename, std::fstream::app);
  if (!file.is_open()) {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }
  file << msg;
  file.close();
}


/*
 * Function: double_equals
 * Description: checks equivalenc eof double within an epsilon value
 */
static inline bool double_equals(double a, double b, double epsilon = 0.00001) {
  return std::abs(a - b) < epsilon;
}

/*
 * Function: remove_trailing_zeroes
 * Description: removes zeroes at end of a string, keeps last zero
 */
static inline std::string &remove_trailing_zeroes(std::string &str) {
  size_t index_cutoff = str.find_last_not_of('0');
  if (index_cutoff == 1) {
    ++index_cutoff;
  }
  ++index_cutoff;
  str = str.erase(index_cutoff, std::string::npos);
  return str;
}

/*
 * Function: cut_quotes
 * Description: Removes first and last char from string if is a quote
 */
static inline std::string cut_quotes(std::string &str) {
  char front = str.front();
  char back = str.at(str.size()-1);
  if (back == '\'' || back == '\"')
    str.pop_back();
  if (front == '\'' || front == '\"')
    str.erase(str.begin());
  return str;
}
static inline std::string cut_quotes(const std::string &str) {
  std::string res_str = str;
  return cut_quotes(res_str);
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
 * Function: str_is_label
 * Description: if string is formatted like lAbEl1
 */
static inline bool str_is_label(const std::string &str) {
  if (str.size() < 1) return false;
  if (!isalpha(str[0])) return false;
  for (size_t i = 0; i < str.size(); ++i) {
    if (!isalnum(str[i])) return false;
  }
  return true;
}

/*
 * Function: stringtochar
 * Description: determines if string like "\n", " " is a char
 */
static inline char stringtochar(const std::string &str) {
  if (str.size() > 2 && str[0] != '\\') return 0;
  if (str.size() == 2) {
    char c = str[1];
    // is space
    if (c == 'n') return '\n';
    if (c == 't') return '\t';
    if (c == 'v') return '\v';
    if (c == 'f') return '\f';
    if (c == 'r') return '\r';
  }
  return str[0];
}

/*
 * Function: ischarchar
 * Description: true if representable character like ' ' or '$'
 */
static inline bool ischarchar(char c) {
  if (c >= 32 && c <= 176) return true; /* <! All ascii chars that can be viewed > */
  if (isspace(c)) return true;
  return false;
}

/*
 * Function: isstringchar
 * Description: true if is a representable character like ' ' or '$'
 */
static inline bool isstringchar(char c) {
  if (c == '\"') return false;
  return ischarchar(c);
}

/*
 * Function: str_is_char
 * Description: if string is formatted like 'c', ' ', or '$'
 */
static inline bool str_is_char(const std::string &str) {
  if (str.size() > 4) return false;
  if (str.size() > 2) 
  if (str[0] != '\'') return false;
  if (str[str.size()-1] != '\'') return false;
  std::string tmp_str = str;
  cut_quotes(tmp_str);
  if (!ischarchar(stringtochar(tmp_str))) return false;
  return true;
}


/*
 * Function: str_is_string
 * Description: if string is formatted like "sTrInG1"
 */
static inline bool str_is_string(const std::string &str) {
  if (str[0] != '\"') return false;
  if (str[str.size()-1] != '\"') return false;
  for (size_t i = 1; i < str.size() - 1; ++i) {
    if (!isstringchar(str[i])) return false;
  }
  return true;
}

/*
 * Function: str_is_real
 * Description: if string is formatted like 54
 */
static inline bool str_is_real(const std::string &str) {
  for (size_t i = 0; i < str.size(); ++i) {
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
  for (size_t i = 0 ; i < str.size(); ++i) {
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
  for (size_t i = 2; i < str.size(); ++i) {
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
 * Function: get_full_string_token
 * Description: given a string, retrieves string bounded by first quote it encounters from prev index to the current index
 */
static inline std::string get_full_string_token(const std::string &str, size_t curr_i, size_t prev_i) {
  int true_prev_i = prev_i + 1;
  for (int i = prev_i + 1; i < curr_i; ++i) {
    if (str[i] == '\"') {
      true_prev_i = i;
      break;
    }
  }
  std::string result = str.substr(true_prev_i, curr_i - true_prev_i + 1);
  trim(result);
  return result;
}

/*
 * Function: c_str_to_string
 * Description: similar to substring, given start and end of c str, returns as string
 */
static inline std::string c_str_to_string(const char *frm, const char *to) {
  std::string str;
  while (frm < to) {
    str += *frm++;
  }
  return str;
}

/*
 * Function: split_not_quote
 * Description: returns string tokens as vector given a c string, delimited by commas, ws ignored, supports quotes
 */
static std::vector<std::string> split_not_quote(const char *s) {
  std::vector<std::string> strings;
  const char *start;
  int state = ',';
  while (*s) {
    switch (state) {
      case '\f':
      case '\v':
      case '\t':
      case '\b':
      case '\n':
      case ',':
      case ' ': // Consuming spaces
        if (*s == '\"') {
          start = s;
          state = '\"';  // begin quote
        } else if (*s != ' ') {
          start = s;
          state = 'T';
        }
        break;
      case 'T': // non-quoted text
        if (*s == ',') {
          strings.push_back(c_str_to_string(start, s));
          state = ',';
        } else if (*s == '\"') {
          state = '\"'; // begin quote
        }
        break;
      case '\"': // Inside a quote
        if (*s == '\"') {
          state = 'T'; // end quote
        }
        break;
    }
    s++;
  } // end while
  if (state != ' ') {
    strings.push_back(c_str_to_string(start, s));
  }
  return strings;
}

/*
 * Function: split_line
 * Description: splits string into tokens delimited by comma and \n, returns vector of the string tokens
 */
static inline std::vector<std::string> split_line(const std::string &str) {
  return split_not_quote(str.c_str());
}

/*
 * Function: remove_opname
 * Description: given a vector of strings, remove the the operation name from first token
 */
static inline std::string remove_opname(std::vector<std::string> &str_toks) {
  std::string &first = str_toks.front();
  int index = first.find(" ");
  std::string opname = first.substr(0, index);
  first = first.substr(index + 1);
  trim(first);
  return opname;
}

/*
 * Function: split_line_getopname
 * Description: splits the string into string tokens, and cuts and stores the operation name
 */
static inline std::vector<std::string> split_line_getopname(const std::string &str, std::string &opname) {
  std::vector<std::string> strings = split_line(str);
  if (strings.empty()) return strings;
  opname = remove_opname(strings); 
  return strings;
}

#endif
