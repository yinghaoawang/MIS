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
      //TODO hardcode
      cache->variables["str"] = new Variable(1.0);
    }

    void PrintOperations() {
      std::cout << "printing operations:" << std::endl;
      std::cout << "variables: " << cache->variables.size() << std::endl;
      for (auto it = cache->operations.begin(); it != cache->operations.end(); ++it) {
        (*it)->Execute();
      }
    }

    void ReadFile(char* filename) {
      std::ifstream ifs(filename);
      if (!ifs.is_open()) {
        std::cerr << "coudl not open shit" << std::endl;
        return;
      }

      int line_number;
      std::string op_name;
      std::string line;
      for (line_number = 1;ifs.good(); ++line_number) {

        get_opname_line(ifs, op_name, line);
        auto op = parser_factory->GetParser(op_name)->ParseOp(cache, line);

        if (op == nullptr) {
          continue;
        }

        cache->operations.push_back(op);
      }

      PrintOperations();
      ifs.close();
    }
};

#endif
