int main() {
  // common cases (not much difference between NULL and 0)
  int* p1 = nullptr;

  // usage in overloaded functions
  void f(char const *p);
  void f(int v);
  f(NULL); // intending to call char const *int constructor, but the int constructor is called
  f(nullptr); // calls char const *int constructor as planned

  // one may even have a nullptr value constructor
  void f(nullptr_t);
  return 0;
}
