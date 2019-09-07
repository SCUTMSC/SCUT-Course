// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A program to generate the moves needed to solve the Towers of Hanoi
// problem.
// There are two versions. One is a simple recursive implementation.
// The other replaces the recursion with a stack.

#include "book.h"

typedef int Pole; // A simple definition for a pole type

// What to do when we "move" a disk: Print it out
#define move(X, Y) cout << "Move " << (X) << " to " << (Y) << endl

// A simple recursive function that generates the solution steps
void TOH(int n, Pole start, Pole goal, Pole temp) {
  if (n == 0) return;          // Base case
  TOH(n-1, start, temp, goal); // Recursive call: n-1 rings
  move(start, goal);           // Move bottom disk to goal
  TOH(n-1, temp, goal, start); // Recursive call: n-1 rings
}

// Now we show how to do this by replacing recursion with a stack.

// Include the standard stack template implementation
#include "astack.h"

// Now, we need to define the objects to be put on the stack
// TOHobj describes an operation to perform. 
// It has 5 members: Operation type, number of disks to operate on,
// and the designations (start, goal, temp) for the three poles.
// There are two operation types.
// (i) DOTOH describes what originally was a recursive call.
// It defines the pole order and the number of disks to be moved.
// (ii) DOMOVE describes a move operation.
// It defines the start and goal pole for the disk to be moved.
class TOHobj { // An operation object
public:
  TOHop op;              // This operation type
  int num;               // How many disks
  Pole start, goal, tmp; // Define pole order

  // DOTOH operation constructor
  TOHobj(int n, Pole s, Pole g, Pole t) {
    op = DOTOH; num = n;
    start = s; goal = g; tmp = t;
  }

  // DOMOVE operation constructor
  TOHobj(Pole s, Pole g)
    { op = DOMOVE; start = s; goal = g; }
};

// This is the stack version of the function that solves the TOH problem
void TOH(int n, Pole start, Pole goal, Pole tmp,
         Stack<TOHobj*>& S) {
  S.push(new TOHobj(n, start, goal, tmp)); // Initial
  TOHobj* t;
  while (S.length() > 0) {       // Grab next task
    t = S.pop();
    if (t->op == DOMOVE)   // Do a move
      move(t->start, t->goal);
    else if (t->num > 0) {
      // Store (in reverse) 3 recursive statements
      int num = t->num;
      Pole tmp = t->tmp;  Pole goal = t->goal;
      Pole start = t->start;
      S.push(new TOHobj(num-1, tmp, goal, start));
      S.push(new TOHobj(start, goal));
      S.push(new TOHobj(num-1, start, tmp, goal));
    }
    delete t; // Must delete the TOHobj we made
  }
}

int main(int argc, char** argv) {

  Assert(argc == 2, "Usage: toh <num_of_disks>");

  int n = atoi(argv[1]);
  cout << "Doing recursive version on " << n << " disks\n";
  TOH(n, 1, 3, 2);

  cout << endl;

  AStack<TOHobj*> S(2*n+1); // Make a stack with just enough room
  cout << "Now, do non-recursive version\n";
  TOH(n, 1, 3, 2, S);

  return 0;
}
