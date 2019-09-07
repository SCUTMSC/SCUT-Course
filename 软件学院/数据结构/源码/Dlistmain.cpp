// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the doubly-linked list class

#include "book.h"

// Include comparator functions
#include "compare.h"

// Include doubly linked node implementation
#include "dlinkFL.h"

// Include doubly linked list implementation
#include "dlist.h"

#include "ListTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LList<Int*> L1;
  LList<Int*> L2(15);
  LList<Int> L3;

  ListTest<Int*, Int, LList<int> >(L1, L2, L3);
  return 0;
}
