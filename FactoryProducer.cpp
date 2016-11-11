#include "FactoryProducer.h"
#include "AbstractFactory.h"
#include "ParserFactory.h"
#include "OperationFactory.h"

AbstractFactory *FactoryProducer::GetFactory(std::string choice) {
  if (choice == "PARSER") return new ParserFactory();
  if (choice == "OPERATION") return new OperationFactory();
  return nullptr;
}
