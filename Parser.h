#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <map>
#include <exception>
#include "OperationFactory.h"
#include "Operation.h"
#include "Token.h"
#include "Variable.h"
#include "Util.h"
#include "Cache.h"

class Parser {
  protected:
    Token StrToLabelTok(Cache * const cache, const std::string &label_name) {
      if (!str_is_label(label_name)) {
        std::string str_err = "invalid label name for jump: " + label_name;
        throw std::runtime_error(str_err);
      }

      Label *label;
      if (cache->HasLabel(label_name)) {
        label = cache->GetLabel(label_name);
      } else {
        label = new Label(label_name, -1);
        cache->SetLabel(label);
      }

      Token t = Token(label);
      return t;
    }

    bool HasValidParamsCount(int params_count, int min, int max) {
      if (params_count < min || params_count > max) {
        std::string str_err = "wrong param count: expected " + std::to_string(min) + "-" + std::to_string(max) + ", got " + std::to_string(params_count);
        throw std::runtime_error(str_err);
      }
      return true;
    }

    Token StrToTok(Cache * const cache, const std::string &str) {
      if (str_is_variable(str)) {
        std::string varname = str.substr(1);
        if (!cache->HasVariable(varname)) {
          std::string str_err = "variable does not exist: " + varname;
          throw std::runtime_error(str_err);
        }

        Variable *v = cache->GetVariable(varname);
        return Token(v);
      }

      if (str_is_numeric(str)) {
        double d = std::stod(str);
        return Token(d);
      }

      if (str_is_real(str)) {
        long l = std::stol(str);
        return Token(l);
      }

      if (str_is_char(str)) {
        char c = str[1];
        return Token(c);
      }

      if (str_is_string(str)) {
        return Token(cut_quotes(str).c_str());
      }

      std::string str_err = "invalid param type: " + str;
      throw std::runtime_error(str_err);
    }

    Token StrToNumTok(Cache *cache, std::string &str) {
      if (str_is_variable(str)) {
        std::string varname = str.substr(1);

        if (!cache->HasVariable(varname)) {
          std::string str_err = "variable does not exist: " + varname;
          throw std::runtime_error(str_err);
        }

        Variable *v = cache->GetVariable(varname);
        if (!v->IsNumber()) {
          std::string str_err = "variable " + varname + " is not number";
          throw std::runtime_error(str_err);
        }
        return Token(v);
      }

      if (str_is_numeric(str)) {
        double d = std::stod(str);
        return Token(d);
      }

      if (str_is_real(str)) {
        long l = std::stol(str);
        return Token(l);
      }

      std::string str_err = "not a number: " + str;
      throw std::runtime_error(str_err);
    }

  public:
    virtual Parser *Clone()=0;
    virtual std::vector<Token> Tokenize(Cache * const, const std::string&)=0;

    Operation *ParseOp(Cache * const cache, const std::string &line, const std::string &op_name) {
      OperationFactory *operation_factory = new OperationFactory();

      std::vector<Token> tokens;

      try {
        tokens = Tokenize(cache, line);
      } catch (std::exception &e) {
        std::cerr << "error: " << e.what() << std::endl;
        return nullptr;
      }

      auto operation = (operation_factory->GetOperation(op_name))->Clone();

      operation->SetParams(tokens);
      return operation;
    }
};

class AddParser : public Parser {
  public:
    AddParser() {}
    virtual Parser *Clone() {
      Parser *p = new AddParser();
      return p;
    }

    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 3, 13);

      if (!cache->HasVariable(str_toks.front().substr(1))) {
        std::string str_err = "requires variable as first param, given: " + str_toks.front();
        throw std::runtime_error(str_err);
      }

      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
        tokens.push_back(StrToNumTok(cache, *it));
      }

      return tokens;
    }
};

class SleepParser : public Parser {
  public:
    SleepParser() {}
    virtual Parser *Clone() {
      Parser *p = new SleepParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 1, 1);

      Token t = StrToNumTok(cache, str_toks.front());
      tokens.push_back(t);
      return tokens;
    }

};

class JmpznzParser : public Parser {
  public:
    JmpznzParser() {}
    virtual Parser *Clone() { return new JmpznzParser(); }
    virtual std::vector<Token> Tokenize(Cache * const cache, const  std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 2, 2);
      Token t1 = StrToLabelTok(cache, str_toks[0]);
      Token t2 = StrToNumTok(cache, str_toks[1]);
      tokens.push_back(t1);
      tokens.push_back(t2);
      return tokens;
    }
};

class JmpglteParser : public Parser {
  public:
    JmpglteParser() {}
    virtual Parser *Clone() { return new JmpglteParser(); }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 3, 3);

      Token t1 = StrToLabelTok(cache, str_toks[0]);
      Token t2 = StrToNumTok(cache, str_toks[1]);
      Token t3 = StrToNumTok(cache, str_toks[2]);
      tokens.push_back(t1);
      tokens.push_back(t2);
      tokens.push_back(t3);
      return tokens;
    }
};

class JmpParser : public Parser {
  public:
    JmpParser() {}
    virtual Parser *Clone() { return new JmpParser(); }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 1, 1);

      std::string label_name = str_toks.front();
      Token t = StrToLabelTok(cache, label_name);
      tokens.push_back(t);
      return tokens;
    }
};

class LabelParser : public Parser {
  public:
    LabelParser() {}
    virtual Parser *Clone() {
      Parser *p = new LabelParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 1, 1);

      std::string label_name = str_toks.front();
      if (!str_is_label(label_name)) {
        std::string str_err = "invalid label name: " + label_name;
        throw std::runtime_error(str_err);
      }

      int op_index = cache->GetOperationSize();

      Label *label;
      if (cache->HasLabel(label_name)) {
        Label *cached_label = cache->GetLabel(label_name);
        if (cached_label->GetIndex() >= 0) {
          std::string str_err = "label already exists " + label_name;
          throw std::runtime_error(str_err);
        }
        cached_label->SetIndex(op_index);
        label = cached_label;
      } else {
        label = new Label(label_name, op_index);
        cache->SetLabel(label);
      }

      Token t = Token(label);
      tokens.push_back(t);

      return tokens;
    }
};

class AssignParser : public Parser {
  public:
    AssignParser() {}
    Parser *Clone() { return new AssignParser(); }

    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);

      HasValidParamsCount(str_toks.size(), 2,2);
      std::string varname = str_toks.at(0);
      Variable *v = cache->GetVariable(varname.substr(1));
      if (v == nullptr) {
        std::string str_err = "variable not found: " + varname;
        throw std::runtime_error(str_err);
      }
      Token tok1 = Token(v);
      Token tok2 = StrToTok(cache, str_toks.at(1));

      if (tok1.GetType() != tok2.GetType()) {
        std::string str_err = "non matching get type for assignment";
        throw std::runtime_error(str_err);
      }


      tokens.push_back(tok1);
      tokens.push_back(tok2);
      return tokens;
    }
};

class VarParser : public Parser {
  private:
    bool HasValidVarType(std::string &var_name, std::string &var_type, std::string &var_data) {
      if (var_type == "NUMERIC" && !str_is_numeric(var_data)) {
        std::string str_err = "not of type NUMERIC: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "REAL" && !str_is_real(var_data)) {
        std::string str_err = "not of type REAL: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "CHAR" && !str_is_char(var_data)) {
        std::string str_err = "not of type NUMERIC: " + var_data;
        throw std::runtime_error(str_err);
      }
      if (var_type == "STRING" && !str_is_string(var_data)) {
        std::string str_err = "not of type STRING: " + var_data;
        throw std::runtime_error(str_err);
      }
      return true;
    }
    Token VarToTok(std::string &var_name, std::string &var_type, std::string &var_data, int var_strlen) {
      Data data;
      if (var_type == "NUMERIC") {
        double d = std::stod(var_data);
        data = Data(d);
      } else if (var_type == "REAL") {
        long l = stol(var_data);
        data = Data(l);
      } else if (var_type == "CHAR") {
        char c = var_data.at(0);
        data = Data(c);
      } else if (var_type == "STRING") {
        data = Data(var_data, var_strlen);
      } else {
        std::string str_err = "invalid variable type: " + var_type;
        throw std::runtime_error(str_err);
      }
      Variable *v = new Variable(var_name, data);
      Token t = Token(v);
      return t;
    }

    bool HasValidStringSize(std::string &str, size_t size) {
      if (str.size() - 2 > size) {
        std::string str_err = "string size greater than specified size: " + std::to_string(str.size() - 2) + " > " + std::to_string(size);
        throw std::runtime_error(str_err);
      }
      return true;
    }

    void SetVariable(std::vector<std::string> const &str_toks, std::string &var_name, std::string &var_type, std::string &var_data, int &var_strlen) {
      var_name = str_toks.at(0);
      if (!str_is_variable(var_name)) {
        std::string str_err = "invalid string name: " + var_name;
        throw std::runtime_error(str_err);
      }
      var_name.erase(var_name.begin());
      if (str_toks.size() >= 2 && str_toks.at(1) == "STRING") {
        HasValidParamsCount(str_toks.size(), 4, 4);
        var_type = str_toks.at(1);
        var_strlen = std::stoi(str_toks.at(2));
        var_data = str_toks.at(3);
        HasValidStringSize(var_data, var_strlen);
      } else {
        HasValidParamsCount(str_toks.size(), 3, 3);
        var_type = str_toks.at(1);
        var_data = str_toks.at(2);
      }

    }

  public:
    VarParser() {}
    virtual Parser *Clone() {
      Parser *p = new VarParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::string opname;
      std::vector<std::string> str_toks = split_line_getopname(str, opname);

      std::string var_name;
      std::string var_type;
      std::string var_data;
      int var_strlen;

      SetVariable(str_toks, var_name, var_type, var_data, var_strlen);
      HasValidVarType(var_name, var_type, var_data);
      if (var_type == "STRING" || var_type == "CHAR") var_data = cut_quotes(var_data);

      Token t = VarToTok(var_name, var_type, var_data, var_strlen);
      cache->SetVariable(t.GetVariable());
      tokens.push_back(t);
      return tokens;
    }
};

class OutParser : public Parser {
  public:
    OutParser() {}
    virtual Parser *Clone() {
      return new OutParser();
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);
      if (str_toks.front() == "OUT") remove_vector_front(str_toks);

      HasValidParamsCount(str_toks.size(), 1, 12);
      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
        Token t = StrToTok(cache, *it);
        tokens.push_back(t);
      }
      return tokens;
    }
};

class SubParser : public Parser {
  public:
    SubParser() {}
    virtual Parser *Clone() {
      Parser *p = new SubParser();
      return p;
    }
    virtual std::vector<Token> Tokenize(Cache * const cache, const std::string &str) {
      std::vector<Token> tokens;
      std::vector<std::string> str_toks = split_line(str);
      remove_opname(str_toks);
      HasValidParamsCount(str_toks.size(), 3, 3);
      if (!cache->HasVariable(str_toks.front().substr(1))) {
        std::string str_err = "requires variable as first param, given: " + str_toks.front();
        throw std::runtime_error(str_err);
      }
      for (auto it = str_toks.begin(); it != str_toks.end(); ++it) {
        tokens.push_back(StrToNumTok(cache, *it));
      }
      return tokens;
    }
};

#endif
