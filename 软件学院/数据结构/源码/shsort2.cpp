// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Optimized Shell Sort implementation and timing test driver

#include "book.h"
#include "compare.h"

// Optimized Shell sort implementation, uses "division by 3's"
// to determine growth in list sizes
// Modified version of Insertion Sort for varying increments
template <typename E, typename Comp>
void inssort2(E A[], int n, int incr) {
  for (int i=incr; i<n; i+=incr)
    for (int j=i; (j>=incr) && (Comp::prior(A[j], A[j-incr])); j-=incr)
      swap(A, j, j-incr);
}

template <typename E, typename Comp>
void shellsort(E A[], int n) {
  int firstincr;
  for (firstincr = 1; firstincr<=n; firstincr = firstincr*3 + 1);
  for (int i=firstincr/3; i>2; i/=3)
    for (int j=0; j<i; j++)
      inssort2<E,Comp>(&A[j], n-j, i);
  inssort2<E,Comp>(A, n, 1);    // Could call regular inssort
}

template <typename E, typename Comp>
void sort(E* array, int n) {
  shellsort<E,Comp>(array, n);
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<minintCompare>(argc, argv);
}
