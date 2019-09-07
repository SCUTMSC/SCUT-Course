// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked list class implemented with a free list

#include "book.h"

// Include the comparator classes
#include "compare.h"

// Inlude the version of the link template class that
// uses a freelist
#include "linkFL.h"

// Include the linked list template class
#include "llist.h"

#include "ListTest.h"

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LList<Int*> L1;
  LList<Int*> L2(15);
  LList<Int> L3;

  ListTest<Int*, Int, LList<int> >(L1, L2, L3);
  return 0;
}
