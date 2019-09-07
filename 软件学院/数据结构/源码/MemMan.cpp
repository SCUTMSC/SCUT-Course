// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Program for testing the syntax of the memory manager code

typedef int MemHandle;

#include "MemMan.h"

// Make the abstract class concrete so that the compiler will not complain
class MemConc: public MemManager {
public:
  MemHandle insert(void* space, int length) { return 0; }
  void release(MemHandle h) {}
  void get(void* space, MemHandle h, int size) {}
};

int main(int argc, char** argv) {

// example code from book

int* p = new int[5];
int* q = new int[10];
p = q;

  return 0;
}
