// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Implementation for a dictionary based on Skiplists

#include "book.h"

#include "skiplist.h"

// Warning: This test driver has horrible memory leaks.
// Everytime the program does a remove to "it", the next time "it"
// gets used, that previous Int object gets clobbered.
int main()
{
  SkipList<int, Int*> sl;
  Int* it;

  cout << "Size: " << sl.size() << "\n";
  sl.insert(100, new Int(100));
  sl.print();
  cout << "Size: " << sl.size() << "\n";
  it = sl.remove(10);
  sl.print();
  cout << "Size: " << sl.size() << "\n";
  sl.clear();
  cout << "Size: " << sl.size() << "\n";
  sl.insert(15, new Int(15));
  cout << "Size: " << sl.size() << "\n";
  if ((it = sl.find(20)) != NULL)
    cout << "Found " << it << endl;
  else cout << "No key 20\n";
  if ((it = sl.find(15)) != NULL)
    cout << "Found " << it << endl;
  else cout << "No key 15\n";
  sl.print();
  if ((it = sl.remove(20)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 20\n";
  cout << "Now, insert 20\n";
  sl.insert(20, new Int(20));
  sl.print();
  if ((it = sl.remove(20)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 20\n";
  sl.print();
  sl.insert(700, new Int(700));
  cout << "Size: " << sl.size() << "\n";
  sl.insert(350, new Int(350));
  sl.insert(201, new Int(201));
  sl.insert(170, new Int(170));
  sl.insert(151, new Int(151));
  sl.insert(190, new Int(190));
  sl.insert(1000, new Int(1000));
  sl.insert(900, new Int(900));
  sl.insert(950, new Int(950));
  sl.insert(10, new Int(10));
  sl.print();
  if ((it = sl.find(1000)) != NULL)
    cout << "Found " << it << endl;
  else cout << "No key 1000\n";
  if ((it = sl.find(999)) != NULL)
    cout << "Found " << it << endl;
  else cout << "No key 999\n";
  if ((it = sl.find(20)) != NULL)
    cout << "Found " << it << endl;
  else cout << "No key 20\n";
  cout << "Now do some delete tests.\n";
  if ((it = sl.remove(15)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 15\n";
  sl.print();
  if ((it = sl.remove(151)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 151\n";
  sl.print();
  if ((it = sl.remove(151)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 151\n";
  if ((it = sl.remove(700)) != NULL)
    cout << "Removed " << it << endl;
  else cout << "No key 700\n";
  sl.print();
  sl.clear();
  sl.print();
  cout << "Size: " << sl.size() << "\n";

  cout << "Finally, test iterator\n";
  sl.insert(3500, new Int(3500));
  sl.insert(2010, new Int(2010));
  sl.insert(1700, new Int(1700));
  sl.insert(1510, new Int(1510));
  sl.insert(1900, new Int(1900));
  sl.insert(10000, new Int(10000));
  sl.insert(9000, new Int(9000));
  sl.insert(9500, new Int(9500));
  sl.insert(100, new Int(100));
  sl.print();
//  while (sl.size() > 0)
//    cout << sl.removeAny() << " ";
//  cout << "\n";
  return 0;
}
