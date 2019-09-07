// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Implementation and test driver for UNION/FIND implemented with a
// parent-pointer tree. This version does not use path compression.

#include "book.h"
#define ROOT -1

// Parent-pointer tree implementation (without path compression)
#include "ufs.h"

// Driver to test the implementation, mainly its syntax
int main(int argc, char** argv) {
  ParPtrTree* gt = new ParPtrTree(10);
  gt->UNION(1, 2);
  cout << gt->differ(0, 1) << endl;
  cout << gt->differ(2, 1) << endl;
  return 0;
}
