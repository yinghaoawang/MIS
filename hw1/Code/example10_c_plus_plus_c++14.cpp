#include <iostream>
#include <bitset>

int main() {
  int a = 0b01010101;
  int b = 0b10101011;
  // bitset outputs the binary representation of the value
  std::cout << std::bitset<8>(a | b) << '\n'; // output 11111111
  std::cout << std::bitset<8>(a & b) << '\n'; // output 00000001
