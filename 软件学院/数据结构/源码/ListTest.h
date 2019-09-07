// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Full template version of find function
template <typename Key, typename E, typename Compare, typename getKey>
bool findt(List<E>& L, Key K, E& it) {
  for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
    it = L.getValue();
    if (Compare::eq(K, getKey::key(it))) return true;
  }
  return false;  // Value not found
}

// Specialization of the find function for ints, as used in the book.
// This int-based version is used at that point in the book so that
// the issues of comparators and keys can be deferred.
// Return true if "K" is in list "L", false otherwise
bool find(List<int>& L, int K) {
  int it;
  for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
    it = L.getValue();
    if (K == it) return true;  // Found K
  }
  return false;                // K not found
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
  // We don't want to screw up the current position of the list
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i=0; i<currpos; i++) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}


// Here is test code to exercise the various methods
template <typename E1, typename E2, typename ListImp>
void ListTest(List<E1>& L1, List<E1>& L2, List<E2>& L3) {
  E1 temp1;
  E1 temp2;
  E2 temp3;

  lprint(L2);
  cout << "Size: " << L2.length() << endl;
  L2.clear();

  L2.insert(new Int(1));
  lprint(L2);
  cout << "Size: " << L2.length() << endl;
  L2.clear();

  L2.append(new Int(1));
  lprint(L2);
  cout << "Size: " << L2.length() << endl;

  L2.clear();
  L2.append(new Int(1));
  L2.moveToEnd();
  lprint(L2);
  L2.clear();

  // Test a bunch of list operations
  L2.append(new Int(1));
  temp2 = L2.remove();
  lprint(L2);
  L2.append(new Int(10));
  lprint(L2);
  L2.append(new Int(20));
  L2.append(new Int(15));
  lprint(L2);
  L1.moveToStart();
  L1.insert(new Int(39));
  L1.next();
  L1.insert(new Int(9));
  L1.insert(new Int(5));
  L1.append(new Int(4));
  L1.append(new Int(3));
  L1.append(new Int(2));
  L1.append(new Int(1));
  lprint(L1);
  L1.moveToStart();
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 3, temp1))
    cout << "Value 3 not found.\n";
  else cout << "Found " << temp1 << endl;
  lprint(L1);
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 3, temp1))
    cout << "Value 3 not found.\n";
  else cout << "Found " << temp1 << endl;
  lprint(L1);
  L1.moveToStart();
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 29, temp1))
    cout << "Value 29 not found.\n";
  else cout << "Found " << temp1 << endl;
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 5, temp1))
    cout << "Value 5 not found.\n";
  else cout << "Found " << temp1 << endl;
  L1.moveToStart();
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 5, temp1))
    cout << "Value 5 not found.\n";
  else cout << "Found " << temp1 << endl;

  L2.moveToStart();
  if (L2.currPos()<L2.length()) {
    temp2 = L2.getValue();
    cout << "L2 curr: " << temp2 << endl;
  }
  else
    cout << "L2: Nothing found\n";
  cout << "L1: ";  lprint(L1);
  cout << "Size: " << L1.length() << endl;
  cout << "L2: ";  lprint(L2);
  cout << "L3: ";  lprint(L3);
  L3.insert(3);
  cout << "L3: ";  lprint(L3);
  L2.moveToStart();
  L2.next();
  L1.moveToStart();
  if (L1.currPos()<L1.length()) {
    temp1 = L1.getValue();
    cout << "L1 curr: " << temp1 << endl;
  }
  else
    cout << "L1: Nothing found\n";
  if (L1.currPos()<L1.length()) {
    temp1 = L1.remove();
    cout << "Deleted: " << temp1 << endl;
  }
  else
    cout << "L1: Nothing found\n";

  L1.insert(new Int(42));
  lprint(L1);
  L1.moveToStart();
  if (! findt<int, E1, intintCompare, getIntsKey>(L1, 4, temp1))
    cout << "Value 4 not found.\n";
  else cout << "Found " << temp1 << endl;
  L2.moveToStart();

  if (L2.currPos()<L2.length()) {
    temp2 = L2.remove();
    cout << "Deleted: " << temp2 << endl;
  }
  else
    cout << "L2: Nothing found\n";

  if (L2.currPos()<L2.length()) {
    temp2 = L2.remove();
    cout << "Deleted: " << temp2 << endl;
  }
  else
    cout << "L2: Nothing found\n";

  lprint(L2);
  cout << "Size: " << L2.length() << endl;
  L2.clear();  lprint(L2);
  cout << "Size: " << L2.length() << endl;
  L2.append(new Int(5));  lprint(L2);
  L2.moveToEnd();

  cout << "Print it again\n";
  lprint(L2);

  if (L2.currPos()<L2.length()) {
    temp1 = L2.getValue();
    cout << "L2 curr: " << temp2 << endl;
  }
  else
    cout << "L2: Nothing found\n";

  if (L2.currPos()<L2.length()) {
    temp2 = L2.remove();
    cout << "Deleted: " << temp2 << endl;
  }
  else
    cout << "L2: Nothing to remove!\n";

  cout << "Start a new round\n";
  L2.clear();
  cout << "cleared\n";
  lprint(L2);
  L2.moveToStart();
  L2.insert(new Int(1));
  lprint(L2);
  L2.insert(new Int(2));
  lprint(L2);
  L2.moveToPos(2);
  L2.insert(new Int(3));
  cout << "L2: "; lprint(L2);
  cout << "L1: "; lprint(L1);
  temp1 = L1.remove();
  cout << "L1: "; lprint(L1);
  L2.clear();

  cout << "Now, test int find\n";
  ListImp MyList;
  MyList.insert(3);
  if (! find(MyList, 3))
    cout << "Value 3 not found.\n";
  else cout << "Found 3\n";
  if (! find(MyList, 13))
    cout << "Value 13 not found.\n";
  else cout << "Found 13\n";

  cout << "That is all.\n";
}
