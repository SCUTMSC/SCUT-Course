// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program tests various code fragements from
// Chapter 3, mainly for syntactic correctness.

#include "book.h"

#include "permute.h"

// Dummy function for the example of section 3.8
int value(int x) { return x; }

// Dummy sort function for c3p13.book and c3p16.book
int sort(int *x, int count) { return count; }

// Since the array used in this fragment is two dimensional, bury it
// in its own function to avoid conflicting with the use in other
// fragments.
void foo(int n) {
  int A[n][n];
  int i, j, tmp;

// Exercise 3.10d
for (i=0; i < n-1; i++)
  for (j=i+1; j < n; j++) {
    tmp = A[i][j];
    A[i][j] = A[j][i];
    A[j][i] = tmp;
  }

}

int main() {
  int sum;
  int i, j, k;
  int n = 100;
  int a;
  int b = 15;
  int *A;
  int sum1, sum2;

  Randomize();

  if ((A = (int *)calloc(n, sizeof(int))) == NULL) {
    cout << "Error: Unable to allocate space for permutation array\n";
    exit(-1);
  }

// Example 3.3, a simple double loop
sum = 0;
for (i=1; i<=n; i++)
   for (j=1; j<=n; j++)
      sum++;
  cout << "Test 1: For n = " << n << ", sum is " << sum << "\n";
  cout << "(It should be n^2.)\n";

// Example 3.9, a simple assignment
a = b;
  cout << "Test 2: b is " << b << " and a is " << a << "\n";

// Example 3.10, a single loop making a simple summation
sum = 0;
for (i=1; i<=n; i++)
   sum += n;
  cout << "Test 3: For n = " << n << ", n^2 is " << sum << "\n";

// Example 3.11, two loops, one nested
sum = 0;
for (i=1; i<=n; i++)     // First for loop
   for (j=1; j<=i; j++)  //   is a double loop
      sum++;
for (k=0; k<n; k++)      // Second for loop
   A[k] = k;
  cout << "Test 4: For n = " << n << ", the sum from 1 to n is "
       << sum << "\n";

// Example 3.12, two loops
sum1 = 0;
for (i=1; i<=n; i++)     // First double loop
   for (j=1; j<=n; j++)  //   do n times
      sum1++;

sum2 = 0;
for (i=1; i<=n; i++)     // Second double loop
   for (j=1; j<=i; j++)  //   do i times
      sum2++;
  cout << "Test 5: This should be n^2: " << sum1 << " (n = " << n << ")\n";
  cout << "Again, the sum from 1 to n is " << sum2 << "\n";

// Example 3.12, two loops with doublings of the index variable
sum1 = 0;
for (k=1; k<=n; k*=2)    // Do log n times
   for (j=1; j<=n; j++)  // Do n times
      sum1++;

sum2 = 0;
for (k=1; k<=n; k*=2)    // Do log n times
   for (j=1; j<=k; j++)  // Do k times
      sum2++;
  cout << "Test 6: For n = " << n << ", the sum of n taken log n times is: "
       << sum1 << "\n";
  cout << "For n = " << n << ", the sum of 2^j is: " << sum2 << "\n";

  int c = 1;
  int d = 2;
  int e = 3;

// Exercise 3.10a
a = b + c;
d = a + e;
  cout << "Done part 7\n";
  a = d ;

// Exercise 3.10b
sum = 0;
for (i=0; i<3; i++)
   for (j=0; j<n; j++)
      sum++;
  cout << "Done part 8\n";

// Exercise 3.10c
sum=0;
for (i=0; i<n*n; i++)
   sum++;
  cout << "Done part 9\n";

  // Call code for Exercise 3.10d
  foo(10);

  cout << "Done part 10\n";
  cout << "Finally, do part 11.\n";

  for (i=0; i<n; i++)
    A[i] = i;

  permute(A, n);

// Exercise 3.10e
sum = 0;
for (i=1; i<=n; i++)
  for (j=1; j<=n; j*=2)
    sum++;
  cout << "Sum should be about n log n: " << sum << "\n";

// Exercise 3.10f
sum = 0;
for (i=1; i<=n; i*=2)
  for (j=1; j<=n; j++)
    sum++;
  cout << "Sum should be about n log n: " << sum << "\n";

// Exercise 3.10g
for (i=0; i<n; i++) {
  for (j=0; j<n; j++)
    A[i] = Random(n);
  sort(A, n);
}
  cout << "Done 13\n";

  for (i=0; i<n; i++)
    A[i] = i;
  permute(A, n);
// Exercise 3.10h
sum = 0;
for (i=0; i<n; i++)
  for (j=0; A[j]!=i; j++)
    sum++;
    cout << "Part 14, sum should be about one half n^2: " << sum << "\n";

// Exercise 3.10i
sum = 0;
if (EVEN(n))
  for (i=0; i<n; i++)
    sum++;
else
  sum = sum + n;
  cout << "Final sum should just be 100: " << sum << "\n";

// Example from Section 3.8 on multiple parameters
  int *count = NULL;
  int C=10, P=100;
  for (i=0; i<C; i++)   // Initialize count
     count[i] = 0;
  for (i=0; i<P; i++)   // Look at all of the pixels
     count[value(i)]++; // Increment a pixel value count
  sort(count, C);       // Sort pixel value counts

  return 0;
}
