#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class Heap {
  private:
    int *array;
    void adjust (int[], int, int);
    int MaxSize, Nel;
  public:
    Heap(const Heap&);
    Heap(int);
    int size() const;
    int &operator[](int);
    int& operator[](int) const;
    Heap& operator=(const Heap&);
    Heap operator+(const Heap&) const;
    Heap operator+(int) const;
    Heap& operator+=(const Heap&);
    Heap& operator+=(const int);
    bool insert(int);
    bool delMax(int&);
    ~Heap();
};

ostream& operator<<(ostream&, const Heap&);

#endif
