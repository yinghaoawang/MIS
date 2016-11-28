#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
  Heap h = Heap(8);
  printf("h = Heap(8) initilialized\n");
  h.insert(4);
  h.insert(3);
  h.insert(2);
  h.insert(1);
  printf("h inserts 4, then 3, then 2, then 1\n");
  printf("h count is %d\n", h.size());
  printf("outputting using cout << h:\n");
  cout << h << '\n';
  cout << endl;

  Heap j = Heap(100);
  printf("j = Heap(100) initilized\n");
  j += h;
  printf("j += h: ");
  cout << j << '\n';
  printf("j += j: ");
  j += j;
  cout << j << '\n';
  cout << endl;

  Heap i = Heap(h);
  printf("i = Heap(h) initialized\n");
  cout << i << '\n';
  printf("i += 99\n");
  i += 99;
  cout << i << '\n';
  i = j + h;
  printf("i = j + h\n");
  cout << i << '\n';
  cout << endl;

  return 0;
}
