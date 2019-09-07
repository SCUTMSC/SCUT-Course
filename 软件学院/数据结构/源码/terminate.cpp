// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Driver program for a little function that repreatedly divides a
// real number in half. Does it terminate?

#include "book.h"

// This function will keep dividing the given value in half, until
// it cannot tell that number from zero. In a real program, this is
// a bad way to test for zero when using floating-point arithmetic.
void foo (double val) {
  if (val != 0.0)
    foo(val/2.0);
}

int main(int argc, char** argv)
{
  cout << "About to start foo.\n";
  foo(8.0);
  cout << "foo terminated on 8.0.\n";
  foo(5.0);
  cout << "foo terminated on 5.0.\n";
}
