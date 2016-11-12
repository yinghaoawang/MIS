#ifndef VM_H_
#define VM_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Variable.h"
#include "Label.h"
#include "Operation.h"
#include "OperationFactory.h"
#include "Parser.h"
#include "Util.h"

class VM {
  private:
    OperationFactory *operation_factory;
    Parser parser;

    std::vector<Operation*> operations;
    std::map<std::string, Variable*> variables;
    std::map<std::string, Label*> labels;

  public:
    VM() {
      Init();
    }
    void Init() {
      operation_factory = new OperationFactory();
      parser = Parser(operations, variables, labels);
    }
    ~VM() {
      for (auto it = operations.begin(); it != operations.end(); ++it) { delete *it; }
      for (auto it = variables.begin(); it != variables.end(); ++it) { delete it->second; }
      for (auto it = labels.begin(); it != labels.end(); ++it) { delete it->second; }
    }

    void PrintOperations() {
      std::cout << "printop" << std::endl;
      for (auto it = operations.begin(); it != operations.end(); ++it) {
        (*it)->Execute();
      }
    }

    void ReadFile(char* filename) {
      std::ifstream ifs(filename);
      if (!ifs.is_open()) {
        std::cerr << "coudl not open shit" << std::endl;
        return;
      }

      int line_number = 1;
      std::string op_name;
      std::string line;
      for (;ifs.good(); ++line_number) {

        getline(ifs, line);
        auto op = parser.ParseOp(line);

        if (op == nullptr) {
          continue;
        }

        operations.push_back(op);
      }

      PrintOperations();
      ifs.close();
    }
};

#endif
