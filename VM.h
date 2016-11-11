#ifndef VM_H_
#define VM_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Variable.h"
#include "Label.h"
#include "Operation.h"
#include "Parser.h"
#include "Factory.h"
#include "Util.h"

class VM {
  private:
    FactoryProducer factory_producer;
    AbstractFactory *operation_factory;
    AbstractFactory *parser_factory;

    std::vector<Operation*> operations;
    std::map<std::string, Variable*> variables;
    std::map<std::string, Label*> labels;

  public:
    VM() {
      Init();
    }
    void Init() {
      factory_producer = FactoryProducer();
      operation_factory = factory_producer.GetFactory("OPERATION");
      parser_factory = factory_producer.GetFactory("PARSER");
    }

    void PrintOperations() {
      std::cout << "printop" << std::endl;
      for (auto it = operations.begin(); it != operations.end(); ++it) {
        (*it)->execute();
      }
    }

    void ReadFile(char* filename) {
      std::ifstream ifs(filename);
      if (!ifs.is_open()) {
        std::cerr << "coudl not open shit" << std::endl;
        return;
      }

      std::string op_name;
      std::string line;
      while (ifs.good()) {
        get_opname_line(ifs, op_name, line);
        auto parser = parser_factory->GetParser(op_name);
        if (parser == nullptr) {
          std::cerr << "unrecognized operation " << op_name << " from parser" << std::endl;
          delete parser;
          continue;
        }
        Operation *op = parser->ParseOp(line);
        operations.push_back(op);
        delete parser;
      }

      PrintOperations();
      ifs.close();
    }
};

#endif
