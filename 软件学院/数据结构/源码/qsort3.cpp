// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Quicksort implementation and timing test driver
// Quicksort optimized to inline all function calls and replace recursion
// with a stack

#include "book.h"

// Include comparator functions
#include "compare.h"

// Quicksort core function: No function calls and no recursion
template <typename E, typename Comp>
void qsort(E array[], int i, int j) {
  int stack[200];
  int top = -1;
  E pivot;
  int pivotindex, l, r;

  stack[++top] = i;
  stack[++top] = j;

  while (top > 0) {
    // Pop stack
    j = stack[top--];
    i = stack[top--];

    // Findpivot
    pivotindex = (i+j)/2;
    pivot = array[pivotindex];
    swap(array, pivotindex, j); // stick pivot at end

    // Partition
    l = i-1;
    r = j;
    do {
      while (Comp::prior(array[++l], pivot));
      while (r && Comp::prior(pivot,array[--r]));
      swap(array, l, r);
    } while (l < r);
    swap(array, l, r);          // Undo final swap
    swap(array, l, j);          // Put pivot value in place

    // Load up stack.  l is pivot point.
    if ((l-1) > i) {
      stack[++top] = i;
      stack[++top] = l-1;
    }
    if (j > (l+1)) {
      stack[++top] = l+1;
      stack[++top] = j;
    }
  }
}

template <typename E, typename Comp>
void sort(E* array, int n) {
  qsort<E,Comp>(array, 0, n-1);
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<minintCompare>(argc, argv);
}
