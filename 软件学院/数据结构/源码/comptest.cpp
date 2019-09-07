// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A timing test to see how much overhead is caused by using comparators
// We time three version: a comparator classe for ints, 
// a comparator class for ints with the function members declared inline,
// and raw comparison of ints (no comparator class)

#include "book.h"

// Define a standard comparator class for ints
class intintCompare {
public:
  static bool lt(int x, int y) { return x < y; }
  static bool eq(int x, int y) { return x == y; }
  static bool gt(int x, int y) { return x > y; }
};

// Same as above, but inline the functions
class iiiComp {
public:
  inline static bool lt(int x, int y) { return x < y; }
  inline static bool eq(int x, int y) { return x == y; }
  inline static bool gt(int x, int y) { return x > y; }
};


// Driver for doing the timing tests
int main(int argc, char** argv) {
  int a = 10;
  int b = 20;
  bool dum;

  Assert(argc == 2, "Usage: comptest <numruns>");

  int numruns = atoi(argv[1]);
  int i;

  //  For each test, we do many calls to the comparator within
  // the loop to minimize the overhead costs.

  Settime();
  for(i=0; i<numruns; i++) {
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
    dum = intintCompare::lt(a, b);
  }
  cout << "Time for class comparison: "
	   << Gettime() << " sec\n";

  Settime();
  for(i=0; i<numruns; i++) {
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
    dum = iiiComp::lt(a, b);
  }
  cout << "Time for inline'd class comparison: "
	   << Gettime() << " sec\n";

  Settime();
  for (i=0; i<numruns; i++) {
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
    dum = a < b;
  }
  cout << "Time for simple comparison: "
       << Gettime() << " sec\n";

  return 0;
}
