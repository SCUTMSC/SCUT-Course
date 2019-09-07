// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A simple program to compute factorials. There are two versions.
// One is a standard recursive form. The other imitates recursion
// using a stack.

#include "book.h"

long fact(int n) {       // Compute n! recursively
  // To fit n! into a long variable, we require n <= 12
  Assert((n >= 0) && (n <= 12), "Input out of range");
  if (n <= 1)  return 1; // Base case: return base solution
  return n * fact(n-1);  // Recursive call for n > 1
}

// This version uses a stack to replace the recursive calls
#include "astack.h"
long fact(int n, Stack<int>& S) { // Compute n!
  // To fit n! in a long variable, require n <= 12
  Assert((n >= 0) && (n <= 12), "Input out of range");
  while (n > 1) S.push(n--);  // Load up the stack
  long result = 1;            // Holds final result
  while(S.length() > 0)
     result = result * S.pop();   // Compute
  return result;
}

int main(int argc, char** argv)
{
  int n;

  Assert(argc == 2, "Usage: fact <n>");

  n = atoi(argv[1]);

  cout << "First, do the recursive version.\n";
  long val = fact(n);
  cout << "The factorial of " << n << " is " << val << endl;

  cout << "\nNow, do the stack-based version.\n";
  long val2 = 1;
  if (n>0) {
    AStack<int> fs(n-1);  // Make stack just big enough
    val2 = fact(n, fs);
  }
  cout << "The factorial of " << n << " is " << val2 << endl;

  return 0;
}
