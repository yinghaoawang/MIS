#include "AbstractFactory.h"
#include "Parser.h"

Operation* AbstractFactory::GetOperation(std::string str) { return nullptr; }
Parser* AbstractFactory::GetParser(std::string str) { return nullptr; }
