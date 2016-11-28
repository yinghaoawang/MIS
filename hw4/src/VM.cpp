#include "VM.h"
// Constructor
VM::VM() {
  Init();
}

// Initialize the VM with its factories and cache
void VM::Init() {
  cache = new Cache();
  operation_factory = new OperationFactory();
  parser_factory = new ParserFactory();
}

// Loop through its cache's operations, and execute them
void VM::ExecuteOperations() {
  for (int prog_counter = 0; prog_counter < cache->GetOperationSize(); ++prog_counter) {
    try {
      // The output returned is the output of the operation
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

// Given a stream, push the set of operations from the interpreted stream to the cache
void VM::ReadBuffer(std::stringstream &ss) {
  static int op_index = 0;
  std::string op_name;
  std::string line;
  while (ss.good()) { // Loop though each line of the stream
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
    cache->CheckLabelValidity(); // See if there are any labels that point to < 0
  } catch(std::exception &e) {
    std::string error = "compiletime error: " + std::string(e.what()) + "\n";
  }
}
void VM::ReadBuffer(const char* buffer) { // Overloading
  std::stringstream ss;
  ss << buffer;
  ReadBuffer(ss);
}

// Given a filename, push interpreted operations from lines in the file to cache
void VM::ReadFile(const char* filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Could not open file " << filename << std::endl;
    return;
  }
  std::cout << "Reading file: " << filename << std::endl;
  // put the file into a stringstream and then read it as a buffer
  std::stringstream ss;
  copy(std::istreambuf_iterator<char>(ifs),
       std::istreambuf_iterator<char>(),
       std::ostreambuf_iterator<char>(ss));
  ifs.close();
  ReadBuffer(ss);
}

// Read output that is stored from runtime (execution)
void VM::ReadOutput(char* dest) {
  strcpy(dest, outstream.str().c_str());
}

// Read errors that is stored from compiling and runtime (execution)
void VM::ReadError(char* dest) {
  strcpy(dest, errstream.str().c_str());
}
