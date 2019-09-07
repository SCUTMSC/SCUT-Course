// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A simple program to calculate the Fibonacci sequence.
// Two versions are provided: One that uses recursion (and whose cost is
// therefore exponential), and one that works iteratively (and whose
// cost is linear).

#include "book.h"

// The recursive version (exponential cost)
long fibr(int n) { // Recursive Fibonacci generator
  // fibr(46) is largest value that fits in a long
  Assert((n > 0) && (n < 47), "Input out of range");
  if ((n == 1) || (n == 2)) return 1; // Base cases
  return fibr(n-1) + fibr(n-2);       // Recursion
}

// The iterative version (linear cost)
long fibi(int n) { // Iterative Fibonacci generator
  // fibi(46) is largest value that fits in a long
  Assert((n > 0) && (n < 47), "Input out of range");
  long past, prev, curr;  // Store temporary values
  past = prev = curr = 1;    // initialize
  for (int i=3; i<=n; i++) { // Compute next value
    past = prev;             // past holds fibi(i-2)
    prev = curr;             // prev holds fibi(i-1)
    curr = past + prev;      // curr now holds fibi(i)
  }
  return curr;
}

int main(int argc, char** argv) {
  int n;

  Assert(argc == 2, "Usage: fib <n>");

  n = atoi(argv[1]);

  Settime();
  cout << "Fibi(" << n << ") = " << fibi(n) << endl;
  cout << "Fibi time: " << Gettime() << " seconds.\n";

  Settime();
  cout << "Fibr(" << n << ") = " << fibr(n) << endl;
  cout << "Fibr time: " << Gettime() << " seconds.\n";

  return 0;
}
