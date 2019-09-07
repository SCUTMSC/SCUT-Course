// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the sorted array-based list class

#include "book.h"

// Include the array-based list template code
#include "alist.h"

#include "KVpair.h"

// This is the specialization for sorted lists
#include "salist.h"

// Driver class for sorted array-based list implementation

int main(int argc, char** argv) {
  // Declare some sample lists
  SAList<int,Int*> L1;
  SAList<int,Int*> L2(15);
  SAList<int,Int> L3;

  Int dum;
  KVpair<int,Int>* T2;
  T2 = new KVpair<int,Int>(5, 5);
  L3.insert(*T2);
  delete(T2);
  T2 = new KVpair<int,Int>(3, 3);
  L3.insert(*T2);
  delete(T2);
  T2 = new KVpair<int,Int>(7, 7);
  L3.insert(*T2);
  delete(T2);
  //  L3.print();
  L3.movetoStart();
  KVpair<int,Int> temp2;
  while (L3.currPos() < L3.length()) {
    temp2 = L3.remove();
    cout << "Removed " << temp2.key() << endl;
  }
  //  L3.print();
  return 0;
}
