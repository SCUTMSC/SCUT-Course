// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Perform binary search on an array. There are two versions:
// One that uses a template and a comparator, and one that works
// only for a simple int array.

#include "book.h"
#include "compare.h"

// This version is generalized to use a template for elements,
// and a comparator.
// Return the position of an element in a sorted array of
// size n with key value K.  If none exist, return n.
template<typename Key, typename E, typename Comp, typename getKey>
int binaryt(E array[], int n, Key K) {
  int l = -1;
  int r = n;     // l and r are beyond the bounds of array
  while (l+1 != r) {   // Stop when l and r meet
    int i = (l+r)/2;   // Check middle of remaining subarray
    if (Comp::lt(K, getKey::key(array[i]))) r = i;    // In left half
    if (Comp::eq(K, getKey::key(array[i]))) return i; // Found it
    if (Comp::gt(K, getKey::key(array[i]))) l = i;    // In right half
  }
  return n; // Search value not in array
}

// This is the version that appears in the book.
// It works on an integer array.
// Return the position of an element in sorted array "A" of
// size "n" with value "K".  If "K" is not in "A", return
// the value "n".
int binary(int A[], int n, int K) {
  int l = -1;
  int r = n;          // l and r are beyond array bounds
  while (l+1 != r) {  // Stop when l and r meet
    int i = (l+r)/2;  // Check middle of remaining subarray
    if (K < A[i]) r = i;     // In left half
    if (K == A[i]) return i; // Found it
    if (K > A[i]) l = i;     // In right half
  }
  return n; // Search value not in A
}

// Test program to test out both the specific and the generic bsearch
// algorithm.
int main(int argc, char** argv) {
  int i, numvals, K, result;
  int* A;
  Int* B;
  Int** C;

  Assert(argc == 3, "Usage: bsearch <num_values> <search_key>");

  numvals = atoi(argv[1]);
  K = atoi(argv[2]);

  // Create and initialize array
  A = new int[numvals];
  B = new Int[numvals];
  C = new Int*[numvals];
	
  for (i=0; i<numvals; i++)
    A[i] = i;

  // Call to specialized implementation (integer only)
  result = binary(A, numvals, K);
  if (result == numvals)
    cout << "Binary search was unsuccessful\n";
  else
    cout << "Binary search returns " << result << "\n";

  for (i=0; i<numvals; i++)
    { A[i] = i; B[i] = i; C[i] = new Int(i); }

  // Call to generalized template form
  result = binaryt<int, int, intintCompare, getintKey>(A, numvals, K);
  if (result == numvals)
    cout << "Binary search was unsuccessful\n";
  else
    cout << "Binary search returns " << result << "\n";

  result = binaryt<int, Int, intintCompare, getIntKey>(B, numvals, K);
  if (result == numvals)
    cout << "Binary search was unsuccessful\n";
  else
    cout << "Binary search returns " << result << "\n";

  // Call to generalized template form
  result = binaryt<int, Int*, intintCompare, getIntsKey>(C, numvals, K);
  if (result == numvals)
    cout << "Binary search was unsuccessful\n";
  else
    cout << "Binary search returns " << result << "\n";


  return  0;
}
