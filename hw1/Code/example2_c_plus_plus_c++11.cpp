#include <iostream>
#include <typeinfo>

int main() {
  int i1 = 5;
  decltype(i1); // int

  struct A { double x; };
  auto a = new A;

  decltype(a->x); // double
  int fcn1(); // prototype for function that returns an int
  decltype(fcn1()) l = fcn1();
  printf("%s\n", typeid(decltype(i1)).name()); // outputs parsed decltype to string format "i"

  const int const_i = 0, &const_j = const_i;
  decltype(const_i) i = 0; // i has type const int
  decltype(const_j) j = i; // j has type const int& and is boundt o i
  // decltype(const_j) k; // error: k is a reference and must be initialized

  // decltype of a parenthesized variable is always a reference
  // decltype((const_it)) l; // error: l is a reference and must be initialized

  return 0;
}
