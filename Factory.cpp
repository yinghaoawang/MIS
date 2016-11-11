#include "Factory.h"

std::map<std::string, Parser*> ParserFactory::parsers;
bool ParserFactory::initialized;
std::map<std::string, Operation*> OperationFactory::operations;
bool OperationFactory::initialized;

Parser* AbstractFactory::GetParser(std::string str) { return nullptr; }
Operation* AbstractFactory::GetOperation(std::string str) { return nullptr; }

ParserFactory::ParserFactory() { Init(); }

void ParserFactory::Init() {
  if (!initialized) {
    initialized = true;
    parsers["ADD"] = new AddParser();
    parsers["SUB"] = new SubParser();
  }
}

Parser* ParserFactory::GetParser(std::string str) {
  if (parsers.find(str) != parsers.end()) {
    return parsers[str]->clone();
  }
  return nullptr;
}

OperationFactory::OperationFactory() { Init(); }
void OperationFactory::Init() {
  if (!initialized) {
    initialized = true;
    operations["ADD"] = new AddOperation();
    operations["SUB"] = new SubOperation();
  }
}
Operation* OperationFactory::GetOperation(std::string str) {
  if (operations.find(str) != operations.end()) {
    return operations[str]->clone();
  }
  return nullptr;
}

AbstractFactory *FactoryProducer::GetFactory(std::string choice) {
  if (choice == "PARSER") return new ParserFactory();
  if (choice == "OPERATION") return new OperationFactory();
  return nullptr;
}
