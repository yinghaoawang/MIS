#ifndef PARSERFACTORY_H_
#define PARSERFACTORY_H_

#include <map>
#include "Parser.h"

class ParserFactory {
  private:
    static std::map<std::string, Parser*> parsers;
    static bool initialized;
  public:
    ParserFactory();
    ~ParserFactory();
    void Init();
    Parser* GetParser(std::string&);
    bool HasParser(std::string&);
};

std::map<std::string, Parser*> ParserFactory::parsers;
bool ParserFactory::initialized;

ParserFactory::ParserFactory() { Init(); }

ParserFactory::~ParserFactory() {
  if (initialized) {
    initialized = false;
    for (auto it = parsers.begin(); it != parsers.end(); ++it) {
      delete it->second;
    }
  }
};


void ParserFactory::Init() {
  if (!initialized) {
    initialized = true;
    parsers["ADD"] = new AddParser();
    parsers["SUB"] = new SubParser();
  }
}

bool ParserFactory::HasParser(std::string &str) {
  if (parsers.find(str) == parsers.end()) return false;
  return true;
}

Parser* ParserFactory::GetParser(std::string &str) {
  if (HasParser(str)) {
    return parsers[str]->Clone();
  }
  return nullptr;
}

#endif
