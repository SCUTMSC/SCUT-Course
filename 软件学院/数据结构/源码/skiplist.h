// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file includes all of the pieces of the skiplist implementation
// NOTE: There is no implementation for delete, only insert and find.

// The maximum level of the skiplist is hard-coded. Ideally, it would
// grow dynamically
#define MAXLEVEL 9

#include "dictionary.h"

// Pick a level using an exponential distribution
int randomLevel(void) {
  int level = 0;
  while (Random(2) == 0) level++;
  return level;
}

template <typename Key, typename E>
class SkipNode {
public:
  int myLevel;
  Key k;
  E it;
  SkipNode** forward;
  SkipNode() {
    myLevel = MAXLEVEL;
    forward = new SkipNode* [MAXLEVEL+1];
    for (int i=0; i<=MAXLEVEL; i++)
      forward[i] = NULL;
  }
  SkipNode(Key key, E r, int level) {
    myLevel = level;
    k = key;
    it = r;
    forward = new SkipNode* [level+1];
    for (int i=0; i<=level; i++)
      forward[i] = NULL;
  }
  ~SkipNode() { delete [] forward; }
};


template <typename Key, typename E>
class SkipList : public Dictionary<Key, E> {
private:
  SkipNode<Key,E>* head;
  int level;
  int reccount;
  void AdjustHead(int& level) {level = MAXLEVEL;}
public:

  SkipList() {
    head = new SkipNode<Key,E>;
    level = MAXLEVEL;
    reccount = 0;
  }

  void clear()
    { cout << "Clear not implemented\n"; }

E find(const Key& k) const {
  SkipNode<Key,E> *x = head;         // Dummy header node
  for (int i=level; i>=0; i--)
    while ((x->forward[i] != NULL) &&
           (k > x->forward[i]->k))
      x = x->forward[i];
  x = x->forward[0];  // Move to actual record, if it exists
  if ((x != NULL) && (k == x->k)) return x->it;
  return NULL;
}

void insert(const Key& k, const E& it) {
  int i;
  SkipNode<Key,E> *x = head;   // Start at header node
  int newLevel = randomLevel(); // Select level for new node
  if (newLevel > level) {     // New node is deepest in list
    AdjustHead(newLevel);     // Add null pointers to header
    level = newLevel;
  }
  SkipNode<Key,E>* update[level+1]; // Track level ends
  for(i=level; i>=0; i--) {   // Search for insert position
    while((x->forward[i] != NULL) && (x->forward[i]->k < k))
      x = x->forward[i];
    update[i] = x;           // Keep track of end at level i
  }
  x = new SkipNode<Key,E>(k, it, newLevel);   // New node
  for (i=0; i<=newLevel; i++) {          // Splice into list
    x->forward[i] = update[i]->forward[i]; // Where x points
    update[i]->forward[i] = x;           // What points to x
  }
  reccount++;
}

  E remove(const Key& K)
    { cout << "Remove not implemented\n"; return false;}

  E removeAny()
    { cout << "Removeany not implemented\n"; return false; }

  int size() { return reccount; }

  void print() const {
    cout << "Print a skiplist with " << reccount << " nodes\n";
    for (SkipNode<Key,E>* temp = head; temp!= NULL;
         temp = temp->forward[0]) {
      if (temp->it != NULL)
        cout << "temp->k is " << temp->k << "\n";
      else cout << "temp->k is NULL\n";
      for(int i=0; i<=temp->myLevel; i++)
        if (temp->forward[i] == NULL)
          cout << " point to NULL\n";
        else
          cout << " point to " << temp->forward[i]->it << "\n";
    }
  }
};

