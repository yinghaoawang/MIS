#ifndef VM_H_
#define VM_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Variable.h"
#include "Label.h"
#include "Operation/Operation.h"
#include "OperationFactory.h"
#include "ParserFactory.h"
#include "Parser/Parser.h"
#include "Util.h"
#include "Cache.h"

class VM {
  private:
    OperationFactory *operation_factory;
    ParserFactory *parser_factory;
    Cache *cache;
  public:
    VM();
    void Init();
    void ExecuteOperations();
    void ReadFile(char* filename);
};

#endif
