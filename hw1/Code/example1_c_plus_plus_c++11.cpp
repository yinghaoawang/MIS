#include <iostream>
#include <vector>
#include <string>

class Dog {
};

int main() {
  std::vector<std::string> container = { "hi", "bye" };
  for (std::vector<std::string>::iterator it = container.begin(); it != container.end(); ++it);
  // long and hard to read

  // now using auto

  for (auto it = container.begin(); it != container.end(); ++it);
  // short, understandable, and clean

  auto a = 1; // int
  auto b = 1.23; // float
  auto c = 1L; // long
  auto d = Dog(); // dog object
  auto e = 1 + (b * 2) * b;

  auto i = 0, *p = &i; // okay i is int, p is pointer to int
  // auto j = 0, q = 2.7; // error: j is in, q is double

  return 0;
}
