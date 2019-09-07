// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Quicksort implementation and timing test driver
// Quicksort optimized to not qsort lists of length <= THRESHOLD,
// Insertion sort is used at the end for a final sort pass

#include "book.h"

// Include comparator functions
#include "compare.h"

extern int THRESHOLD;

// Insertion sort for final cleanup sort pass
template <typename E, typename Comp>
void inssort(E A[], int n) { // Insertion Sort
  for (int i=1; i<n; i++)       // Insert i'th record
    for (int j=i; (j>0) && (Comp::prior(A[j], A[j-1])); j--)
      swap(A, j, j-1);
}

// Simple findpivot: Pick middle value in array
template <typename E>
inline int findpivot(E A[], int i, int j)
  { return (i+j)/2; }

// Partition the array
template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
  do {             // Move the bounds inward until they meet
    while (Comp::prior(A[++l], pivot));  // Move l right and
    while ((l < r) && Comp::prior(pivot, A[--r])); // r left
    swap(A, l, r);              // Swap out-of-place values
  } while (l < r);              // Stop when they cross
  return l;      // Return first position in right partition
}

// qsort core function: do not qsort lists of length <= THRESHOLD
template <typename E, typename Comp>
void qsort(E array[], int i, int j) {
  if ((j-i) <= THRESHOLD) return; // Don't sort short list
  int pivotindex = findpivot(array, i, j);
  swap(array, pivotindex, j); // stick pivot at end
  int k = partition<E,Comp>(array, i-1, j, array[j]);
  swap(array, k, j);          // Put pivot value in place
  qsort<E,Comp>(array, i, k-1);
  qsort<E,Comp>(array, k+1, j);
}

template <typename E, typename Comp>
void sort(E* array, int n) {
   qsort<E,Comp>(array, 0, n-1);
  inssort<E,Comp>(array, n); // Cleanup sort
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<minintCompare>(argc, argv);
}
