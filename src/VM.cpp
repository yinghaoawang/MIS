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
  std::cout << "Executing operations: " << std::endl;
  std::cout << "variables: " << cache->GetVariableSize() << std::endl;

  for (int prog_counter = 0; prog_counter < cache->GetOperationSize(); ++prog_counter) {
    try {
      std::string output = cache->GetOperation(prog_counter)->Execute(prog_counter);
      if (!output.empty()) print_out(output, "mis.out");
    } catch(std::exception &e) {
      std::string error = "runtime error: " + std::string(e.what()) + "\n";
      print_err(error, "mis.err");
    }
  }
}

void VM::ReadFile(char* filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }

  std::cout << "Reading file: " << filename << std::endl;
  static int op_index = 0;
  std::string op_name;
  std::string line;
  while (ifs.good()) {
    get_opname_line(ifs, op_name, line);
    if (trim(op_name).empty()) continue;
    if (!parser_factory->HasParser(op_name) || !operation_factory->HasOperation(op_name)) {
      std::string error = "compiletime error: unrecognized operation: " + op_name + "\n";
      print_err(error, "mis.err");
      continue;
    }
    Operation *op;
    try {
      op = parser_factory->GetParser(op_name)->ParseOp(cache, line, op_name);
    } catch(std::exception &e) {
      std::string error = "compiletime error: " + std::string(e.what()) + "\n";
      print_err(error, "mis.err");
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
  ifs.close();
}
