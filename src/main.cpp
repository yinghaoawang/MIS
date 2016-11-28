#include <iostream>
#include "VM.h"

int main(int argc, char* argv[]) {
  /* MISVM, read file given the filename, then execute the parsed operations */
  VM vm;
  vm.ReadFile(argv[1]);
  vm.ExecuteOperations();

  return 0;
}
