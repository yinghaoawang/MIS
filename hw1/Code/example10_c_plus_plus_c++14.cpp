int main() {
  int int1 = 1, int2 = 2;
  double db1 = 1.1, db2 = 2.2;

  auto lambda_f = [](auto a, auto b) { return a + b; }; // auto parameters, auto return type

  lambda_f(int1, int2); // int: 3
  lambda_f(db1, db2); // double: 3.3
  lambda_f(int1, db2); // double 3.2

}
