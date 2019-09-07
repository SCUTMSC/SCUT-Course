// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Determine the minimum and the maximum from an unsorted array.

#include "book.h"

using std::min;
using std::max;

// Return the minimum and maximum values in A
// between positions l and r
template <typename E>
void MinMax(E A[], int l, int r, E& Min, E& Max) {
  if (l == r) {        // n=1
    Min = A[r];
    Max = A[r];
  }
  else if (l+1 == r) { // n=2
    Min = min(A[l], A[r]);
    Max = max(A[l], A[r]);
  }
  else {               // n>2
    int Min1, Min2, Max1, Max2;
    int mid = (l + r)/2;
    MinMax(A, l, mid, Min1, Max1);
    MinMax(A, mid+1, r, Min2, Max2);
    Min = min(Min1, Min2);
    Max = max(Max1, Max2);
  }
}

#include "permute.h"

int main(int argc, char** argv)
{
  int n;
  int Min, Max;

  Assert(argc == 2, "Usage: minmax <n>");

  n = atoi(argv[1]);

  int* A = new int[n];

  for (int i=0; i<n; i++)
    A[i] = i+1;
  permute(A, n);

  MinMax(A, 0, n-1, Min, Max);
  cout << "Min is: " << Min << ", Max is: " << Max << endl;

  return 0;
}
