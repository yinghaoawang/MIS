#include <iostream>
#include "Heap.h"
using namespace std;

Heap::~Heap() {
  if (array != NULL) free(array);
}

// Base constructor
Heap::Heap(int MSize):MaxSize(MSize) {
  array = (int *) calloc(MSize + 1, sizeof(int));
  Nel = 0;
}

// Copy constructor
/* same max size and values as the other heap */
Heap::Heap(const Heap &other):Heap(other.MaxSize) {
  for (int i = 1; i <= other.size(); ++i) {
    insert(other[i]);
  }
}

/* Heapify */
void Heap::adjust(int a[], int i, int n) {
  int j = 2 * i, item = a[i];
  while (j <= n) {
    if (j < n && (a[j] < a[j+1])) ++j;
    if (item >= a[j]) break;
    a[j/2] = a[j]; j *= 2;
  }
  a[j/2] = item;
}

/* Insert item into heap */
bool Heap::insert (int item) {
  int i = Nel;
  ++i;
  if (i > MaxSize) {
    std::cout << "heap size (" << MaxSize << ") exceeded (value: " << item << " not inserted)" << std::endl;
    return false;
  }
  ++Nel;
  while ((i > 1) && (array[i/2] < item)) {
    array[i] = array[i/2];
    i /= 2;
  }
  array[i] = item;
  return true;
}

/* Pop max, returns 0 if empty, takes in int reference to set max to */
bool Heap::delMax(int &item) {
  if (!Nel) {
    std::cout << "heap is empty" << std::endl;
    return false;
  }
  item = array[1];
  array[1] = array[Nel--];
  adjust(array, 1, Nel);
  return true;
}

/* Get size */
int Heap::size() const {
  return Nel;
}

/* Overload assignment */
/* this one does a copy of the other heap, changes MaxSize, Nel, elements of array, everything */
Heap& Heap::operator=(const Heap &other) {
  if (&other == this) return *this;
  array = (int*) realloc(array, other.MaxSize * sizeof(int));
  Nel = 0;
  MaxSize = other.MaxSize;
  for (int i = 1; i <= other.Nel; ++i) {
    insert(other[i]);
  }
  return *this;
}

/* Combine heaps */
Heap Heap::operator+(const Heap &other) const {
  Heap heap = Heap(MaxSize);
  for (int i = 1; i <= size(); ++i) {
    heap.insert(array[i]);
  }
  for (int i = 1; i <= other.size(); ++i) {
    heap.insert(other[i]);
  }
  return heap;
}

/* insert value into heap */
Heap Heap::operator+(int value) const {
  Heap heap = Heap(*this);
  heap.insert(value);
  return heap;
}

/* plus equal heap */
Heap &Heap::operator+=(const Heap &other) {
  // this is to prevent problem when other == *this
  if (&(*this) == &other) { // other == *this doesnt work because did not write operator
    *this = *this + *this;
    return *this;
  }

  for (int i = 1; i <= other.size(); ++i) {
    insert(other[i]);
  }
  return *this;
}

/* plus equal value */
Heap &Heap::operator+=(const int i) {
  insert(i);
  return *this;
}

/* Subscript overload */
/* const subscript access getter */
int &Heap::operator[](const int i) const {
  return array[i];
}

/* mutator subscript */
int &Heap::operator[](const int i) {
  return array[i];
}

/* Extraction implementation for Heap */
ostream& operator<<(ostream& os, const Heap& heap) {
  for (int i = 1; i <= heap.size(); ++i) os << heap[i] << ' ';
  return os;
}

