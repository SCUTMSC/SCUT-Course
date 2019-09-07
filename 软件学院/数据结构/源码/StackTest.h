// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Calls for testing stack implementations
template <typename E> void StackTest(Stack<E>& St) {
  E temp;

  // Test a bunch of stack operations
  if (St.length() > 0) {
    temp = St.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  St.push(10);
  St.push(20);
  St.push(15);
  cout << "Size is " << St.length() << endl;
  if (St.length() > 0) {
    temp = St.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  while(St.length() > 0) {
    temp = St.pop();
    cout << temp << " ";
  }
  cout << endl;
  if (St.length() > 0) {
    temp = St.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  cout << "Size is " << St.length() << endl;
  St.clear();
  cout << "Size is " << St.length() << endl;
  cout << "That is all.\n\n";
}
