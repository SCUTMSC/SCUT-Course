// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// The number of records (and keys) in a leaf node
const int maxrecs = 10;
// The number of pointers (and keys) in an internal node
const int maxpointers = 10;

// Abstract class definition for B+-trees
template <typename Key, typename E>class BPNode {
public:
  BPNode* lftptr;  BPNode* rghtptr; // Links to siblings
  virtual ~BPNode() {} // Base destructor
  virtual bool isLeaf() const =0;  // True if node is a leaf
  virtual bool isFull() const =0;  // True if node is full
  virtual int numrecs() const =0;  // Current num of records
  virtual Key* keys() const=0;     // Return array of keys
};

// Implementation for leaf node
template <typename Key, typename E>
class BPLeaf : public BPNode<Key, E> {
private:
  Key theKeys[maxrecs];
  E theRecs[maxrecs];
  int currecs; // The number of records now

public:
  BPLeaf() { currecs = 0; }  // constructor
  bool isLeaf() const { return true; }
  bool isFull() const { return (currecs == maxrecs); }
  int numrecs() const { return currecs; }
  Key* keys() { return theKeys; }
  E recs(int which) const { return theRecs[which]; }

  BPNode<Key,E>* del(int which) { return NULL; }
  BPNode<Key,E>* add(Key k, E e) { return NULL; }
};

// Implementation for leaf node
template <typename Key, typename E>
class BPInternal : public BPNode<Key, E> {
private:
  Key theKeys[maxpointers];
  BPNode<Key,E>* thePointers[maxpointers];
  int currecs; // The number of records now

public:
  BPInternal() { currecs = 0; }  // constructor
  bool isLeaf() const { return false; }
  bool isFull() const { return (currecs == maxrecs); }
  int numrecs() const { return currecs; }
  Key* keys() const { return theKeys; }
  BPNode<Key,E>* pointers(int which) const { return thePointers[which]; }

  // stubs
  BPInternal<Key,E>* add(Key k, BPInternal<Key,E>* ptr) { return NULL; }
  bool underflow(int which) { return false; }
};
