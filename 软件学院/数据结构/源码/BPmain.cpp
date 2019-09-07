// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is an outline for a B+ tree implementation. Primarily,
// this code tests the syntax for the outline. It is not a working,
// concrete implementation.

#include "book.h"

#include "dictionary.h"

#include "BPnode.h"

template <typename Key, typename E>
class BPTree : public Dictionary<Key,E> {
private:
  BPNode<Key, E>* root;
  int reccount;
  E findhelp(BPNode<Key,E>* root, const Key k) const;
  BPNode<Key,E>* inserthelp(BPNode<Key,E>* root, const Key& k, const E& e);
  bool removehelp(BPNode<Key,E>* root, const Key& k);

  // Stub for a binary search on the key array
  int binaryle(Key keys[], int cnt, const Key k) const { return 0; }

public:
  BPTree() { root = NULL; reccount = 0; }
  ~BPTree() {};
  void clear() { root = NULL; reccount = 0; } // Memory leak

  void insert(const Key& k, const E& e) { // Insert node
    root = inserthelp(root, k, e);
    reccount++;
  }

  E remove(const Key& k) {
    E temp = findhelp(root, k);
    if (temp != NULL) {
      if (removehelp(root, k) && (root->numrecs() == 1)) // Collapse root
        if (!root->isLeaf()) root = ((BPInternal<Key,E>*)root)->pointers(0);
      reccount--;
    }
    return temp;
  }

  E removeAny() { return NULL; }

  E find(const Key& k) const
    { return findhelp(root, k); }

  int size() { return reccount; }
};

template <typename Key, typename E>
E BPTree<Key, E>::findhelp(BPNode<Key,E>* rt, const Key k)
                           const {
  int currec = binaryle(rt->keys(), rt->numrecs(), k);
  if (rt->isLeaf())
    if ((((BPLeaf<Key,E>*)rt)->keys())[currec] == k)
      return ((BPLeaf<Key,E>*)rt)->recs(currec);
    else return NULL;
  else
    return findhelp(((BPInternal<Key,E>*)rt)->
                             pointers(currec), k);
}

template <typename Key, typename E>
BPNode<Key,E>* BPTree<Key, E>::inserthelp(BPNode<Key,E>* rt,
                        const Key& k, const E& e) {
  if (rt->isLeaf()) // At leaf node: insert here
    return ((BPLeaf<Key,E>*)rt)->add(k, e);
  // Add to internal node
  int currec = binaryle(rt->keys(), rt->numrecs(), k);
  BPNode<Key,E>* temp = inserthelp(
        ((BPInternal<Key,E>*)root)->pointers(currec), k, e);
  if (temp != ((BPInternal<Key,E>*)rt)->pointers(currec))
    return ((BPInternal<Key,E>*)rt)->
                   add(k, (BPInternal<Key,E>*)temp);
  else
    return rt;
}

/** Delete a record with the given key value, and 
    return true if the root underflows */
template <typename Key, typename E>
bool BPTree<Key, E>::removehelp(BPNode<Key,E>* rt,
                                const Key& k) {
  int currec = binaryle(rt->keys(), rt->numrecs(), k);
  if (rt->isLeaf())
    if (((BPLeaf<Key,E>*)rt)->keys()[currec] == k)
      return ((BPLeaf<Key,E>*)rt)->del(currec);
    else return false;
  else // Process internal node
    if (removehelp(((BPInternal<Key,E>*)rt)->
                           pointers(currec), k))
      // Child will merge if necessary
      return ((BPInternal<Key,E>*)rt)->underflow(currec);
    else return false;
}

int main(int argc, char** argv) {
  BPTree<int, Int*>dum;
}
