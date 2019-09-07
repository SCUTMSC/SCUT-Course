// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Two-three tree implementation for the Dictionary ADT
template <typename Key, typename E>
class TTTree : public Dictionary<Key, E> {
private:
  TTNode<Key,E>* root;          // Root of the tree
  int reccount;          // Number of records stored
  // Private "helper" functions
  void clearhelp(TTNode<Key,E>*)                // Helper functions
    { cout << "Clearhelp not yet defined\n"; }
  TTNode<Key,E>* inserthelp(TTNode<Key,E>*, const Key, const E);
  TTNode<Key,E>* add(TTNode<Key,E>*);
  E findhelp(TTNode<Key,E>*, Key) const;
  void printhelp(TTNode<Key,E>*, int) const;

public:
  TTTree() { root = NULL; reccount = 0; }
  ~TTTree() { clearhelp(root); }

  void clear()
    { clearhelp(root);  root = NULL; reccount = 0; }

  // Insert element "it" with Key "k" into the dictionary.
  void insert(const Key& k, const E& e) {
    root = inserthelp(root, k, e);
    reccount++;
  }

  E remove(const Key& k) {
    cout << "Remove not implemented\n";
    return false;
  }

  // Remove and return the record with smallest key value
  // from the dictionary and return in "it". Return true if
  // some record is removed, false otherwise.
  E removeAny() {
    cout << "RemoveAny not implemented\n";
    return false;
  }

  // Return a copy in "it" of some record matching "K".
  // Return true if such exists, false otherwise. If
  // multiple records match "K", return an arbitrary one.
  E find(const Key& k) const
    { return findhelp(root, k); }

  // Return the number of records in the dictionary.
  int size() { return reccount; }

  void print() const {
    cout << "Print tree: \n";
    if (root == NULL) cout << "The 2-3 Tree is empty.\n";
    else printhelp(root, 0);
  }
};
