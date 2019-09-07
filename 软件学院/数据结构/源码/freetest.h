// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test function for comparing freelist implementations
// We will run the timing on three element types in the list, to
// see if the element type affects the relative performance of freelists
// Count is the number of iterations to run on the timing loop
void freetest(long count) {
  Link<int>* test1;         // Try it with int
  Link<Int*>* test2;        // Try it with a pointer to Int
  Link<Int>* test3;         // Try it with an Int stored directly in link
  Int* dum = new Int(10);   // Create an Int to use
  int i;
  double time;

  // For each element type being tested, insert and delete
  // an element from the linked list a bunch of times

  Settime();
  for (i=0; i<count; i++) {
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
    test1 = new Link<int>(i);
    delete test1;
  }
  time = Gettime();

  cout << "Time for int: " << time << endl;

  Settime();
  for (i=0; i<count; i++) {
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
    test2 = new Link<Int*>(dum);
    delete test2;
  }
  time = Gettime();

  cout << "Time for Int*: " << time << endl;

  Settime();
  for (i=0; i<count; i++) {
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
    test3 = new Link<Int>(i);
    delete test3;
  }
  time = Gettime();

  cout << "Time for Int: " << time << endl;
}
