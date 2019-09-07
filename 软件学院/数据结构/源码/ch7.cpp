// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test driver for code bits from Chapter 7 Internal Sorting

int length(int x) { return x; }
void qsort(int a, int b, int c) {}

int main() {
  int i;
  int L = 0; // Really a list, but syntactically irrelevent here

for (i=0; i<length(L); i++)
  qsort(L, 0, i);
for (i=0; i<length(L); i++)
  qsort(L, 0, length(L)-1);
  return 0;
}
