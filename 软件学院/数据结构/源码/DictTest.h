// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

void dicttest(Dictionary<int, Int*> &dict) {
  Int* val;

  dict.insert(10, new Int(10));
  if ((val = dict.find(10)) != NULL)
    cout << "Found value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to match key value 10\n";
  dict.insert(15, new Int(15));
  if ((val = dict.find(5)) != NULL)
    cout << "Found value " << val << " to match key value 5\n";
  else
    cout << "Nothing found to match key value 5\n";
  dict.insert(10, new Int(10));
  cout << "Size is " << dict.size() << endl;
  if ((val = dict.find(10)) != NULL)
    cout << "Found value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to match key value 10\n";
  if ((val = dict.remove(10)) != NULL)
    cout << "Removed value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to match key value 10\n";
  if ((val = dict.find(10)) != NULL)
    cout << "Found value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to match key value 10\n";
  if ((val = dict.remove(10)) != NULL)
	cout << "Remove value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to remove with key value 10\n";
  if ((val = dict.remove(10)) != NULL)
	cout << "Remove value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to remove with key value 10\n";
  cout << "Size is " << dict.size() << endl;
  dict.clear();
  if ((val = dict.find(10)) != NULL)
    cout << "Found value " << val << " to match key value 10\n";
  else
    cout << "Nothing found to match key value 10\n";
  cout << "Size is " << dict.size() << endl;

  cout << "Now, do interator\n";
  dict.insert(25, new Int(25));
  dict.insert(30, new Int(30));
  dict.insert(21, new Int(21));
  Int* e;
  while (dict.size() > 0) {
    e = dict.removeAny();
    cout << "Got element " << e << endl;
  }
}
