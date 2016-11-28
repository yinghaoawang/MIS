#include <iostream>
#include <vector>

int global_num5 = 5;

int main() {
  // basic lambda without parameters
  auto lambda_f = [] { return "hello"; };
  printf("%s\n", lambda_f()); // outputs hello

  // using parameters
  auto smaller = [] (const int &a, const int &b) { return (a < b) ? a : b; };
  printf("%d\n", smaller(1, 2)); // outputs 1

  // using local variables (explicit captures)
  int num1 = 1, num2 = 2;
  auto add1to2 = [num1, num2] { return num1 * num2; }; // would have error if num1, num2 not captured
  printf("%d\n", add1to2()); // outputs 3

  // using implicit capture
  int num3 = 3, num4 = 4;
  auto add3to4to5 = [=] { return num3 + num4 + global_num5; }; // implicit capture with [=]
  printf("%d\n", add3to4to5()); // outputs 12

  // seamless usage with for_each, the lambda taking the place of a function
  std::vector<int> nums { 1, 2, 3, 4, 5 };
  for_each (nums.begin(), nums.end(), [] int  n {
    printf("%d\n", n); // prints each element in int vector nums
  });

  return 0;
}
