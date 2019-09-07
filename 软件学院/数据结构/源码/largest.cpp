// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"
#include "compare.h"
#include "permute.h"

// This is a generalized version of "largest".  It is generalized to use
// a template type for the array elements, and a comparator.
// Return position of the largest value in array of size n
template< class E, class Comp>
int largestt(E array[], int n) {
  int currlarge = 0; // Holds position of largest element
  for (int i=1; i<n; i++) // For each array element
   if (Comp::lt(array[currlarge], array[i])) // if larger
      currlarge = i;                            //   remember it
  return currlarge;       // Return largest position
}

// This is the version of "largest" used in the book, Ch3.
// It works for integer arrays only.
// Return position of largest value in "A" of size "n"
int largest(int A[], int n) {
  int currlarge = 0; // Holds largest element position
  for (int i=1; i<n; i++)   // For each array element
   if (A[currlarge] < A[i]) // if A[i] is larger
      currlarge = i;        //   remember its position
  return currlarge;         // Return largest position
}

// Test driver for "largest" function.
// Build a random permuation of 0 to n-1, and then find the largest value
// Test both the specific version, and the generic.
int main(int argc, char** argv) {
  int* A; // The array
  int n;  // Size of the array
  int i;

  Int* B;
  Int**C;

  Assert(argc == 2, "Usage: largest <size_of_permutation>");

  n = atoi(argv[1]);
  A = new int[n];
  B = new Int[n];
  C = new Int*[n];

  // First, make a random permutation
  for (i=0; i<n; i++) // Initialize array
    { A[i] = i; B[i] = i; C[i] = new Int(i); }

  Randomize();

  permute(A, n);
  permute(B, n);
  permute(C, n);

  for (i=0; i<n; i++) { // Print out permutation
    cout << A[i];
    if (!((i+1)%10))    // Newline every 10th element
      cout << endl;
    else
      cout << "  ";
  }
  if (n%10 != 0) cout << endl;

  // Now, find and report largest value
  int temp = largest(A, n);
  cout << "The largest value position is " << temp << endl;
  cout << "The value is " << A[temp] << "\n\n";

  permute(A, n);

  for (i=0; i<n; i++) { // Print out permutation
    cout << A[i];
    if (!((i+1)%10))    // Newline every 10th element
      cout << endl;
    else
      cout << "  ";
  }
  if (n%10 != 0) cout << endl;

  // Now, find and report largest value
  temp = largestt<int, intintCompare>(A, n);
  cout << "The largest value position is " << temp << endl;
  cout << "The value is " << A[temp] << "\n\n";

  for (i=0; i<n; i++) { // Print out permutation
    cout << B[i];
    if (!((i+1)%10))    // Newline every 10th element
      cout << endl;
    else
      cout << "  ";
  }
  if (n%10 != 0) cout << endl;

  temp = largestt<Int, IntIntCompare>(B, n);
  cout << "The largest value position is " << temp << endl;
  cout << "The value is " << B[temp] << "\n\n";

  for (i=0; i<n; i++) { // Print out permutation
    cout << C[i];
    if (!((i+1)%10))    // Newline every 10th element
      cout << endl;
    else
      cout << "  ";
  }
  if (n%10 != 0) cout << endl;

  temp = largestt<Int*, IntsIntsCompare>(C, n);
  cout << "The largest value position is " << temp << endl;
  cout << "The value is " << C[temp] << "\n";

  return 0;
}
