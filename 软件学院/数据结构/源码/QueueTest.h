// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Calls for testing queue implementations

template <typename E> void QueueTest(Queue<E>& Que) {
  E temp;

  // Test a bunch of queue operations
  Que.enqueue(10);
  Que.enqueue(20);
  Que.enqueue(15);
  cout << "Length is " << Que.length() << endl;
  if (Que.length() > 0) {
    temp = Que.frontValue();
    cout << "Front is " << temp << endl;
  }
  else cout << "Nothing in queue\n";
  while(Que.length() > 0) {
    temp = Que.dequeue();
    cout << temp << " ";
  }
  cout << endl;
  cout << "Length is " << Que.length() << endl;
  if (Que.length() > 0) {
    temp = Que.frontValue();
    cout << "Front is " << temp << endl;
  }
  else cout << "Nothing in queue\n";
  Que.clear();
  cout << "Length is " << Que.length() << endl;
  cout << "That is all.\n\n";
}
