// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program tests that swapping can be done by adding and
// subtracting the values. This is an alternative to using XOR
// to swap without a temporary variable. The thing to be confirmed
// is that overflow and underflow won't mess up the results.

#include "book.h"

int main(int argc, char** argv)
{
  int numtrials = 1000000; // Lets try a million times to break this.
  int a, b; // The values to be swapped
  int origa, origb; // Copies to make sure the swap worked.
  Randomize();


  for (int i=0; i<numtrials; i++) {
    // First, load a and be with random bit patterns.
    a = Random(2);
    b = Random(2);
    for (int j=0; j<31; j++) {
      a = a << 1; a += Random(2);
      b = b << 1; b += Random(2);
    }

    // Now, save them to check later
    origa = a; origb = b;

    // Now, do the swap
    a = a + b;
    b = a - b;
    a = a - b;

    // Now check that it is OK
    if ((a != origb) || (b != origa))
      cout << "ERROR: a was " << origa << ", b was " << origb << endl;
  }

  return 0;
}


