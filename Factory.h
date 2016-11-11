#ifndef FACTORY_H_
#define FACTORY_H_
#include <map>
#include "Parser.h"
#include "Operation.h"

class AbstractFactory {
  virtual Parser* GetParser(std::string str) { return nullptr; }
  virtual Operation* GetOperation(std::string str) { return nullptr; }
};

class ParserFactory : public AbstractFactory {
  static std::map<std::string, Parser*> parsers;
  void Init() {
    parsers["ADD"] = new AddParser();
    parsers["SUB"] = new SubParser();
  }
  Parser* GetParser(std::string str) {
    return parsers[str]->clone();
  }
};

class OperationFactory : AbstractFactory {
  static std::map<std::string, Operation*> operations;
  void Init() {
    operations["ADD"] = new AddOperation();
    operations["SUB"] = new SubOperation();
  }
  Operation* GetOperation(std::string str) {
    return operations[str]->clone();
  }
};

class FactoryProducer {
  public static AbstractFactory GetFactory(String choice) {
  }
};
#endif
