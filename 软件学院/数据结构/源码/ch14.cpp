// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program tests various code fragements from
// Chapter 14, mainly for syntactic correctness.

#include "book.h"

class Stack {
// pop k elements from stack
void multipop(int k);
};


int main() {
  int *A = NULL;

  int sum, i, inc, j;
  int n=0;

for (i=0; ((i<n) && (A[i] == 1)); i++)
  A[i] = 0;
if (i < n)
  A[i] = 1;

sum = 0; inc = 0;
for (i=1; i<=n; i++)
  for (j=1; j<=i; j++) {
    sum = sum + inc;
    inc++;
  }

return 0;
}
