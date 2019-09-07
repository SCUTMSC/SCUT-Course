// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"

// Include permutation function
// Randomly permute the "n" values of array "A"
template<typename E>
void permute(E A[], int n) {
  for (int i=n; i>0; i--)
    swap(A, i-1, Random(i));
}

#include "compare.h"

// Implementation for heap
#include "heap.h"

// Test out the heap implementation -- with max heap
int main(int argc, char** argv) {
  int i, j;
  int n;
  Int* A[20];
  Int* B[20];
  Int C[10] = {73, 6, 57, 88, 60, 34, 83, 72, 48, 85};
  heap<Int*, maxIntsCompare> BH(B, 0, 20);
  heap<Int, maxIntCompare> Test(C, 10, 10);

  if (argc != 2) {
    cout << "Usage: heap <heapsize>\n";
    exit(-1);
  }

  n = atoi(argv[1]);
  if (n > 20) {
    cout << "heap size " << n << " too big.\n";
    exit(-1);
  }

  Randomize();

  for (i=0; i<n; i++)
    A[i] = new Int(i);

  permute(A, n);

  cout << "Initial values:\n";
  for (i=0; i<n; i++) {
    cout << A[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n\n";

  for (i=0; i<n; i++)
    BH.insert(A[i]);

  for (i=0; i<BH.size(); i++) {
    cout << B[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n\n";

  heap<Int*, maxIntsCompare> AH(A, n, 20);
  Int* AHval = NULL;

  for (i=0; i<AH.size(); i++) {
    cout << A[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n\n";

  AHval = AH.removefirst();
  cout << "Max value: " << AHval << "\n";

  for (i=0; i<AH.size(); i++) {
    cout << A[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n\n";

  AHval = AH.removefirst();
  cout << "Max value: " << AHval << "\n";

  for (i=0; i<AH.size(); i++) {
    cout << A[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n\n";

  AHval = AH.remove(2);
  cout << "Remove value: " << AHval << "\n";

  for (i=0; i<AH.size(); i++) {
    cout << A[i] << "  ";
    if (i == 9) cout << "\n";
  }
  cout << "\n";

  for (i=0; i<10; i++)
    cout << C[i] << "  ";
  cout << "\n";

  Int Testval;
  for (j=0; j<10; j++) {
    Testval = Test.removefirst();
    for (i=0; i<10; i++)
      cout << C[i] << "  ";
    cout << "\n";
  }

  return 0;
}
