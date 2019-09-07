// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked queue class

#include "book.h"

#include "lqueue.h"

#include "QueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LQueue<Int> S1;
  LQueue<Int*> S2(15);
  LQueue<int> S3;

  QueueTest<Int>(S1);
  QueueTest<int>(S3);
  return 0;
}
