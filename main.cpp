#include <iostream>
#include "VM.h"
#include "Token.h"

int main(int argc, char* argv[]) {
  VM vm;
  for (int i = 1; i < argc; ++i) {
    vm.ReadFile(argv[i]);
  }

  vm.ExecuteOperations();
  return 0;
}
