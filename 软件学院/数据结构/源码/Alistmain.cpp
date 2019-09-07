// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Array-based list class test program

#include "book.h"

// Include the array-based list template code
#include "alist.h"

// Include the comparator classes
#include "compare.h"

// Generic list test commands
#include "ListTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  AList<Int*> L1;
  AList<Int*> L2(15);
  AList<Int> L3;

  // Call the generic list test functions with an array-based list
  ListTest<Int*, Int, AList<int> >(L1, L2, L3);
  return 0;
}
