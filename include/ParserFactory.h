#ifndef PARSERFACTORY_H_
#define PARSERFACTORY_H_

#include <map>
#include "Parser/Parser.h"

class ParserFactory {
  private:
    static std::map<std::string, Parser*> parsers;
    static bool initialized;
  public:
    ParserFactory();
    ~ParserFactory();
    void Init();
    Parser* GetParser(const std::string&) const;
    bool HasParser(const std::string&) const;
};

#endif
