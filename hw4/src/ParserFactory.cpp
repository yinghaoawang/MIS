#include "ParserFactory.h"
#include "Parser/AddMulParser.h"
#include "Parser/SubDivParser.h"
#include "Parser/VarParser.h"
#include "Parser/LabelParser.h"
#include "Parser/SleepParser.h"
#include "Parser/JmpParser.h"
#include "Parser/AssignParser.h"
#include "Parser/OutParser.h"
#include "Parser/JmpznzParser.h"
#include "Parser/JmpglteParser.h"
#include "Parser/GetStrCharParser.h"
#include "Parser/SetStrCharParser.h"

/* Static variables since they will all be cloned: like a pseudo-singleton */
std::map<std::string, Parser*> ParserFactory::parsers;
bool ParserFactory::initialized;

ParserFactory::ParserFactory() { Init(); }

/* Create new maps of the operations with their respective operation names as keys */
void ParserFactory::Init() {
  if (!initialized) {
    initialized = true;
    parsers["ADD"] = new AddMulParser();
    parsers["SUB"] = new SubDivParser();
    parsers["VAR"] = new VarParser();
    parsers["LABEL"] = new LabelParser();
    parsers["SLEEP"] = new SleepParser();
    parsers["JMP"] = new JmpParser();
    parsers["ASSIGN"] = new AssignParser();
    parsers["OUT"] = new OutParser();
    parsers["JMPZ"] = new JmpznzParser();
    parsers["JMPNZ"] = new JmpznzParser();
    parsers["JMPGT"] = new JmpglteParser();
    parsers["JMPGTE"] = new JmpglteParser();
    parsers["JMPLT"] = new JmpglteParser();
    parsers["JMPLTE"] = new JmpglteParser();
    parsers["MUL"] = new AddMulParser();
    parsers["DIV"] = new SubDivParser();
    parsers["GET_STR_CHAR"] = new GetStrCharParser();
    parsers["SET_STR_CHAR"] = new SetStrCharParser();
  }
}

// Determine if an operation key exists */
bool ParserFactory::HasParser(const std::string &str) const {
  if (parsers.find(str) == parsers.end()) return false;
  return true;
}
Parser* ParserFactory::GetParser(const std::string &str) const {
  if (HasParser(str)) {
    return parsers[str]->Clone();
  }
  return nullptr;
}

// Destructor
ParserFactory::~ParserFactory() {
  if (initialized) {
    initialized = false;
    for (auto it = parsers.begin(); it != parsers.end(); ++it) {
      delete it->second;
    }
  }
};

