// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program tests various code fragements from
// Chapter 4, mainly for syntactic correctness.

#include "book.h"

#include "alist.h"

void doSomething(int elem) {}

int main() {
  AList<int> L1;
  AList<int> L2;
  int it;
  AList<int> L;
  int a = 1, b = 100;
  

a = a + b;
b = a - b; // Now b contains original value of a
a = a - b; // Now a contains original value of b

L1.append(10);
L1.append(20);
L1.append(15);

L2.append(10);
L2.append(20);
L2.append(15);
L2.moveToStart();
L2.insert(39);
L2.next();
L2.insert(12);

for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
  it = L.getValue();
  doSomething(it);
}
}
