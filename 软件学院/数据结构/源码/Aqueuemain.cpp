// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the array-based queue class

#include "book.h"

#include "aqueue.h"

#include "QueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  AQueue<Int> S1;
  AQueue<Int*> S2(15);
  AQueue<int> S3;

  QueueTest<Int>(S1);
  QueueTest<int>(S3);
  return 0;
}
