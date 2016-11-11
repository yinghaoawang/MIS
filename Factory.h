#ifndef FACTORY_H_
#define FACTORY_H_

#include <map>
#include <string>
#include "Parser.h"
#include "Operation.h"

class AbstractFactory {
  public:
    virtual void Init()=0;
    virtual Parser* GetParser(std::string);
    virtual Operation* GetOperation(std::string);
};

class ParserFactory : public AbstractFactory {
  private:
    static std::map<std::string, Parser*> parsers;
    static bool initialized;
  public:
    ParserFactory();
    void Init();
    Parser* GetParser(std::string);
};

class OperationFactory : public AbstractFactory {
  private:
    static std::map<std::string, Operation*> operations;
    static bool initialized;
  public:
    OperationFactory();
    void Init();
    Operation* GetOperation(std::string);
};

class FactoryProducer {
  public:
    AbstractFactory *GetFactory(std::string);
};

#endif
