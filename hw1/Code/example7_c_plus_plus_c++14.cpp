#include <iostream>
#include <vector>
#include <list>
#include <string>

int main() {
  // readability example
  auto foo() { // this line is much shorter compared to std::vector....
    std::vector<std::list<std::string>> result();
    return result;
  }

  // generic programming example
  template <typename Ts, typename Tt>
  auto add(Ts s, Tt t) {
    return s + t; // interprets the return value of the types added together
  }

  return 0;
}
