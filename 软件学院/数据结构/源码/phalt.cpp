// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Syntax check for a "sketch" of the halting problem code.
// Of course, it can't really be implemented. :)

#include "book.h"

bool PROGRAM_HALTS(string prog, string input) { return true; };

bool halt(string prog, string input) {
  if (PROGRAM_HALTS(prog, input))
    return true;
  else
    return false;
}
// Return true if "prog" halts when given itself as input
bool selfhalt(char *prog) {
  if (halt(prog, prog))
    return true;
  else
    return false;
}

// Return the reverse of what selfhalt returns on "prog"
void contrary(char *prog) {
  if (selfhalt(prog))
    while (true); // Go into an infinite loop
}

int main(int argc, char** argv) {
}
