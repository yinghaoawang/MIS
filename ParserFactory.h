#ifndef PARSERFACTORY_H_
#define PARSERFACTORY_H_

#include "AbstractFactory.h"
#include <map>

class ParserFactory : public AbstractFactory {
  private:
    static std::map<std::string, Parser*> parsers;
    static bool initialized;
  public:
    ParserFactory();
    ~ParserFactory();
    void Init();
    Parser* GetParser(std::string);
};

#endif
