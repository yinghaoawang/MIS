#include <iostream>
#include "VM.h"

int main(int argc, char* argv[]) {
  VM vm;
  vm.ReadFile(argv[1]);
  return 0;
}
