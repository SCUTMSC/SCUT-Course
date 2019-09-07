// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Heapsort implementation and timing test driver
// This heapsort has moved all of the utility methods to be part of the
// main heap methods, so that there are far fewer function calls.

#include "book.h"

// Include comparator functions
#include "compare.h"

// Optimized version of heapsort. All node access functions are
// replaced with direct computations on the array indices, so that there
// are far fewer function calls.
template < class E >
void heapsort(E A[], int n)
{ // Heapsort 
  int pos;
  for (int i = n / 2 - 1; i >= 0; i--) {
    pos = i;
    while (pos < n / 2) { // Stop if pos is a leaf 
      int j = 2 * pos + 1;
      if (((j + 1) < n) && (A[j] < A[j + 1]))
	j++; // Set j to greater child's value 
      if (!(A[pos] < A[j]))
	break; // Done 
      {
	E temp = A[pos];
	A[pos] = A[j];
	A[j] = temp;
      } // swap 
      pos = j; // Move down 
    }
  }
  for (n--; n > 0; n--) { // Now sort 
    // Swap max with last value 
    {
      E temp = A[0];
      A[0] = A[n];
      A[n] = temp;
    } // swap 
    pos = 0;
    while (pos < n / 2) { // Stop if pos is a leaf 
      int j = 2 * pos + 1;
      if (((j + 1) < n) && (A[j] < A[j + 1]))
	j++; // Set j to greater child's value 
      if (!(A[pos] < A[j]))
	break; // Done 
      // swap 
      {
	E temp = A[pos];
	A[pos] = A[j];
	A[j] = temp;
      }
      pos = j; // Move down 
    }
  }
}

template <typename E, typename Comp>
void sort(E* array, int n) {
 heapsort(array, n);
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<maxintCompare>(argc, argv);
}
