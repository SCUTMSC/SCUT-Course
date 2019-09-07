// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for KDtree
// This code could be greatly improved. Right now, the coordinate (key)
// is part of the CityRec, which is the element field of the node.
// I'm completely ignoring the Key field. The coodinate array should
// become some sort of specialiation for the key field.
// This data structure should also be integrated with the dictionary ADT,
// (though it will be at least a little different because of the
// regionsearch command).

#include "book.h"

class CityRec {
private:
  string myname;
  int mypos[2];
public:
  // Constructor
  CityRec(int x, int y, string inname) {
    mypos[0] = x;
    mypos[1] = y;
    myname = inname;
  }
  ~CityRec() {delete &myname; }
  string name() { return myname; }
  int* coord() { return mypos; }
};

// Overload << operator to print City records
ostream& operator << (ostream& s, CityRec* p) {
  return s << p->name() << ", " << (p->coord())[0] << ", "
           << (p->coord())[1];
}


#include "binnode.h"

#include "KDtree.h"

int main(int argc, char** argv) {
  CityRec *getCity = NULL;
  CityRec *getCity2 = NULL;
  int coord[2];

  KD<CityRec*>* tree = new KD<CityRec*>(2);

  tree->insert(new CityRec(10, 20, "Acity"));
  tree->print();

  coord[0] = 10; coord[1] = 20;
  tree->remove(coord, getCity2);
  cout << getCity2 << endl;
  tree->print();

  // Insert records for the book example
  tree->insert(new CityRec(40, 45, "A"));
  tree->insert(new CityRec(70, 10, "C"));
  tree->insert(new CityRec(69, 50, "D"));
  tree->insert(new CityRec(15, 70, "B"));
  tree->insert(new CityRec(80, 90, "F"));
  tree->insert(new CityRec(55, 80, "E"));
  tree->print();

  cout << endl << "Do a regionsearch: 80, 90, 0\n";
  coord[0] = 80; coord[1] = 90;
  tree->regionsearch(coord, 0);

  cout << endl << "Do a regionsearch: 25, 65, 25\n";
  coord[0] = 25; coord[1] = 65;
  tree->regionsearch(coord, 25);

  cout << endl << "Now for delete tests" << endl;
  tree->insert(new CityRec(56, 20, "G"));
  tree->insert(new CityRec(57, 25, "H"));
  tree->print();

  coord[0] = 40; coord[1] = 45;
  tree->remove(coord, getCity);
  tree->print();
  return 0;
}
