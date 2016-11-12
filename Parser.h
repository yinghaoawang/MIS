#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "Operation.h"
#include "Token.h"
#include "Util.h"

class Parser {
  private:
    OperationFactory *operation_factory;
    std::vector<Operation*> operations;
    std::map<std::string, Variable*> variables;
    std::map<std::string, Label*> labels;

  public:
    Parser() {}
    Parser(auto ops, auto vs, auto ls):operations(ops),variables(vs),labels(ls) {
      operation_factory = new OperationFactory;
    }
    /* TODO why
    ~Parser() { if (operation_factory != nullptr) delete operation_factory; }
    */
    std::vector<Token> StringsToTokens(std::vector<std::string> &str_toks) {
      std::vector<Token> tokens;
      int i = 0;
      for (auto it = str_toks.begin(); it != str_toks.end(); ++it, ++i) {
        if (i == 0) continue;
        // TODO replace filler code
        std::string varname = "string" + std::to_string(i);
        Variable *v = new Variable(5.0);
        Token t = Token(v);
        tokens.push_back(t);
        variables[varname] = v;
      }
      return tokens;
    }

    Operation *ParseOp(std::string &line) {

      std::vector<std::string> str_toks = split_line(line);
      if (str_toks.empty()) {
        // empty line
        return nullptr;
      }

      std::vector<Token> tokens = StringsToTokens(str_toks);

      if (operation_factory->GetOperation(str_toks.front()) == nullptr) {
        std::cerr << "invalid operation: " << str_toks.front() << std::endl;
        return nullptr;
      }

      auto operation = (operation_factory->GetOperation(str_toks.front()))->Clone();
      operation->SetParams(tokens);

      if (!operation->HasValidParams()) {
        std::cerr << "invalid parameter types for " << str_toks.front() << std::endl;
        return nullptr;
      }
      std::cout << "operation found " << str_toks.front() << std::endl;

      return nullptr;

    }
};

#endif
