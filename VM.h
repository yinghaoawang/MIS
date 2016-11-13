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
#include "ParserFactory.h"
#include "Parser.h"
#include "Util.h"
#include "Cache.h"

class VM {
  private:
    OperationFactory *operation_factory;
    ParserFactory *parser_factory;
    Cache *cache;
  public:
    VM() {
      Init();
    }
    void Init() {
      cache = new Cache();
      operation_factory = new OperationFactory();
      parser_factory = new ParserFactory();
    }

    void ExecuteOperations() {
      std::cout << "Executing operations: " << std::endl;
      std::cout << "variables: " << cache->variables.size() << std::endl;

      for (int prog_counter = 0; prog_counter < cache->GetOperationSize(); ++prog_counter) {
        cache->GetOperation(prog_counter)->Execute(prog_counter);
      }
    }

    void ReadFile(char* filename) {
      std::ifstream ifs(filename);
      if (!ifs.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
      }

      std::cout << "Reading file: " << filename << std::endl;
      static int op_index = 0;
      std::string op_name;
      std::string line;
      while (ifs.good()) {
        get_opname_line(ifs, op_name, line);
        if (trim(op_name).empty()) continue;
        if (!parser_factory->HasParser(op_name)) {
          std::cerr << "unrecognized operation: " << op_name << std::endl;
          continue;
        }
        auto op = parser_factory->GetParser(op_name)->ParseOp(cache, line, op_name);
        if (op == nullptr) continue;

        cache->operations.push_back(op);
        ++op_index;
      }
      try {
        cache->CheckLabelValidity();
      } catch(std::exception &e) {
         std::cerr << "error: " << e.what() << std::endl;
      }
      std::cout << std::endl;
      ifs.close();
    }
};

#endif
