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

    void ReadFile(char* filename) {
      std::ifstream input_file;
      input_file.open(filename);

      std::string op_name;
      std::string line;
      while (input_file.good()) {
        get_opname_line(input_file, op_name, line);
        auto parser = parser_factory->GetParser(op_name);
        Operation *op = parser->ParseOp(line);
        operations.push_back(op);
      }
    }
};

#endif
