// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Heapsort implementation and timing test driver
// This heapsort uses a modified siftdown operation that
// always promotes the larger child regardless of root value.

#include "book.h"

// Include comparator functions
#include "compare.h"

// Implementation of heap with modified siftdown operation
#include "heap2.h"

// Heapsort implementation
template <typename E, typename Comp>
void heapsort(E A[], int n) { // Heapsort
  E maxval;
  heap<E,Comp> H(A, n, n);    // Build the heap
  for (int i=0; i<n; i++)        // Now sort
    maxval = H.removefirst();    // Place maxval at end
}

template <typename E, typename Comp>
void sort(E* array, int n) {
 heapsort<E,Comp>(array, n);
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<maxintCompare>(argc, argv);
}
