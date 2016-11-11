#include "ParserFactory.h"
#include "Parser.h"

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

Parser* ParserFactory::GetParser(std::string str) {
  if (parsers.find(str) != parsers.end()) {
    return parsers[str]->Clone();
  }
  return nullptr;
}

