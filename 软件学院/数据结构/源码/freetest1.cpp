// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Timing test for freelists: Non freelist version
// Compare this running time against freetest2

#include "book.h"

// Include the link template class -- non freelist
#include "link.h"

// Include the timing test used by both versions
#include "freetest.h"

int main(int argc, char** argv) {

  Assert(argc == 2, "Usage: freetest <number_of_iterations>");

  int count = atol(argv[1]);

  freetest(count);

  return 0;
}
