#include <iostream>
#include <string>
#include <vector>

int main() {
  // iterating through an array
  int num[] = { 1, 2, 3, 4, 5 };
  for (int n : nums) {
    printf("%d", n); // output 12345
  }
  printf("\n");

  // iterating through a string
  std::string str("hello");
  for (char c : str) {
    printf("%c", c); // output hello
  }
  printf("\n");

  // iterating througha vector container
  std::vector<int> v_nums = { 1, 2, 3, 4, 5 };
  for (int n : v_nums) {
    printf("%d", n); // output 12345
  }
  return 0;
}
