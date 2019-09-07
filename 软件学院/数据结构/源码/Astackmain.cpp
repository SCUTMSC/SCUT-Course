// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the array-based stack class

#include "book.h"

#include "astack.h"

#include "StackTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  AStack<Int> S1;
  AStack<Int*> S2(15);
  AStack<int> S3;

  StackTest<Int>(S1);
  StackTest<int>(S3);
  return 0;
}
