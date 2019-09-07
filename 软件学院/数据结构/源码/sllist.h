// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is file inludes all the pieces needed for sorted linked lists

// Include linked list node class, implemented with free lists
#include "linkFL.h"
#include "llist.h"

// Specialization code to derive a sorted linked list from the generic
// linked list definition
template <typename Key, typename E>
class SLList: protected LList<KVpair<Key,E> > {
public:
  SLList(int size=DefaultListSize) :
    LList<KVpair<Key,E> >(size) {}
  ~SLList() {}                  // Destructor

  // Redefine insert function to keep values sorted
  void insert(KVpair<Key,E>& it) { // Insert at right
    KVpair<Key,E> curr;
    for (moveToStart(); currPos() < length(); next()) {
      curr = getValue();
      if(curr.key() > it.key())
        break;
    }
    LList<KVpair<Key,E> >::insert(it);
  }

  LList<KVpair<Key,E> >::clear;
  LList<KVpair<Key,E> >::remove;
  LList<KVpair<Key,E> >::moveToStart;
  LList<KVpair<Key,E> >::moveToEnd;
  LList<KVpair<Key,E> >::prev;
  LList<KVpair<Key,E> >::next;
  LList<KVpair<Key,E> >::length;
  LList<KVpair<Key,E> >::currPos;
  LList<KVpair<Key,E> >::moveToPos;
  LList<KVpair<Key,E> >::getValue;
};
