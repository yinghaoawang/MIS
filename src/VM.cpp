#include "VM.h"
VM::VM() {
  Init();
}

void VM::Init() {
  cache = new Cache();
  operation_factory = new OperationFactory();
  parser_factory = new ParserFactory();
}

void VM::ExecuteOperations() {
  for (int prog_counter = 0; prog_counter < cache->GetOperationSize(); ++prog_counter) {
    try {
      std::string output = cache->GetOperation(prog_counter)->Execute(prog_counter);
      if (!output.empty()) {
        outstream << output;
      }
    } catch(std::exception &e) {
      std::string error = "runtime error: " + std::string(e.what()) + "\n";
      errstream << error;
    }
  }
}

void VM::ReadBuffer(std::stringstream &ss) {
  static int op_index = 0;
  std::string op_name;
  std::string line;
  while (ss.good()) {
    get_opname_line(ss, op_name, line);
    if (trim(op_name).empty()) continue;
    if (!parser_factory->HasParser(op_name) || !operation_factory->HasOperation(op_name)) {
      std::string error = "compiletime error: unrecognized operation: " + op_name + "\n";
      errstream << error;
      continue;
    }
    Operation *op;
    try {
      op = parser_factory->GetParser(op_name)->ParseOp(cache, line, op_name);
    } catch(std::exception &e) {
      std::string error = "compiletime error: " + std::string(e.what()) + "\n";
      errstream << error;
      continue;
    }
    if (op == nullptr) continue;

    cache->PushOperation(op);
    ++op_index;
  }
  try {
    cache->CheckLabelValidity();
  } catch(std::exception &e) {
    std::string error = "compiletime error: " + std::string(e.what()) + "\n";
  }
}

void VM::ReadBuffer(const char* buffer) {
  std::stringstream ss;
  ss << buffer;
  ReadBuffer(ss);
}

void VM::ReadFile(const char* filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }
  std::cout << "Reading file: " << filename << std::endl;
  std::stringstream ss;
  copy(std::istreambuf_iterator<char>(ifs),
       std::istreambuf_iterator<char>(),
       std::ostreambuf_iterator<char>(ss));
  ifs.close();
  ReadBuffer(ss);
}

void VM::ReadOutput(char* dest) {
  strcpy(dest, outstream.str().c_str());
}

void VM::ReadError(char* dest) {
  strcpy(dest, errstream.str().c_str());
}
