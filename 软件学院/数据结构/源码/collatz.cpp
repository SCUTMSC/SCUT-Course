// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test out the collatz sequence.

#include "book.h"

int main(int argc, char** argv) {
  int n;

  Assert(argc == 2, "Usage: collatz <start value>");

  // Run book version first, to check the book code for errors.
  // Let's hope it terminates. :-)
  n = atoi(argv[1]);

while (n > 1)
  if (ODD(n))
    n = 3 * n + 1;
  else
    n = n / 2;

  // The book version has no print statement.
  // So, lets run a version with a print statement so that we
  // can see what is going on.
  n = atoi(argv[1]);
  cout << "The start value for the Collatz sequence is: " << n << "\n";

  while (n > 1) {
    if (ODD(n))
      n = 3 * n + 1;
    else
      n = n / 2;
    cout << n << "  ";
  }

  cout << endl;

  return 0;
}
