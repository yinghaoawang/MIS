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
    std::stringstream outstream;
    std::stringstream errstream;
  public:
    VM();
    void Init();
    void ExecuteOperations();
    void ReadFile(const char* filename);
    void ReadBuffer(const char* buffer);
    void ReadBuffer(std::stringstream &ss);
    void ReadOutput(char* dest);
    void ReadError(char* dest);
};

#endif
