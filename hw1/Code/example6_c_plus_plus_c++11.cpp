#include <iostream>
#include <memory>
#include <string>

int main() {
  std::shared_ptr<std::string> p1; // points to a string obj (currently nullptr)
  p1 = std::make_shared<std::string>("hi"); // p1 now points to the string object with "hi"
  auto p2(p1); // p2 and p1 point to same object
  std::cout << p1.use_count() << '\n'; // output 2, amount of pointers to the object
  std::weak_ptr<std::string> p3(p2); // shared_ptr has weak reference
  std::cout << p1.use_count() << '\n'; // output 2, weak_ptr does not influence use_count
  p1.reset(); // p1 points to nullptr, p2 points to obj, use_count is now 1
  p2.reset(); // p1, p2 points to nullptr, since use_count is 0, the object is not destroyed
  // weakptr does not prevent destruction of object, p3 now points to nullptr

  std::unique_ptr<std::string> u_p1 = std::make_unique<std::string>("hello");
  // auto u_p2(u_p1); // error: cannot share object with unique_ptrs
  auto u_p2 = std::move(u_p1); // good: u_p1 points to nullptr, u_p2 points to object with "hello"

  return 0;
}
