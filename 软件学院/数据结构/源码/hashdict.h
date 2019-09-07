// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "dictionary.h"
#include "KVpair.h"

// Dictionary implemented with a hash table
template <typename Key, typename E>
class hashdict : public Dictionary<Key,E> {
private:
  KVpair<Key,E>* HT;   // The hash table
  int M;        // Size of HT
  int currcnt;  // The current number of elements in HT
  Key EMPTYKEY; // User-supplied key value for an empty slot

  int p(Key K, int i) const // Probe using linear probing
    { return i; }

  int h(int x) const { return x % M; } // Poor hash function
  int h(char* x) const { // Hash function for character keys
    int i, sum;
    for (sum=0, i=0; x[i] != '\0'; i++) sum += (int) x[i];
    return sum % M;
  }

  void hashInsert(const Key&, const E&);
  E hashSearch(const Key&) const;

public:
  hashdict(int sz, Key k){ // "k" defines an empty slot
    M = sz;
    EMPTYKEY = k;
    currcnt = 0;
    HT = new KVpair<Key,E>[sz]; // Make HT of size sz
    for (int i=0; i<M; i++)
      (HT[i]).setKey(EMPTYKEY); // Initialize HT
  }

  ~hashdict() { delete HT; }

  // Find some record with key value "K"
  E find(const Key& k) const
    { return hashSearch(k); }
  int size() { return currcnt; } // Number stored in table

  // Insert element "it" with Key "k" into the dictionary.
  void insert(const Key& k, const E& it) {
    Assert(currcnt < M, "Hash table is full");
    hashInsert(k, it);
    currcnt++;
  }
// I took this code out of the book, it doesn't add anything

  // remove not implemented
  E remove(const Key& K) { return NULL; }

  E removeAny() {  // Remove the first element
    Assert(currcnt != 0, "Hash table is empty");
    int i;
    for (i=0; i<M; i++)
      if ((HT[i]).key() != EMPTYKEY) {
        (HT[i]).setKey(EMPTYKEY);
        currcnt--;
	break;
      }
    return (HT[i]).value();
  }

  void clear() { // Clear the dictionary
    for (int i=0; i<M; i++) (HT[i]).setKey(EMPTYKEY);
    currcnt = 0;
  }
};

// Insert e into hash table HT
template <typename Key, typename E>
void hashdict<Key, E>::
hashInsert(const Key& k, const E& e) {
  int home;                     // Home position for e
  int pos = home = h(k);        // Init probe sequence
  for (int i=1; EMPTYKEY != (HT[pos]).key(); i++) {
    pos = (home + p(k, i)) % M; // probe
    Assert(k != (HT[pos]).key(), "Duplicates not allowed");
  }
  KVpair<Key,E> temp(k, e);
  HT[pos] = temp;
}
// Search for the record with Key K
template <typename Key, typename E>
E hashdict<Key, E>::
hashSearch(const Key& k) const {
  int home;              // Home position for k
  int pos = home = h(k); // Initial position is home slot
  for (int i = 1; (k != (HT[pos]).key()) &&
                  (EMPTYKEY != (HT[pos]).key()); i++)  
    pos = (home + p(k, i)) % M; // Next on probe sequence
  if (k == (HT[pos]).key())     // Found it
    return (HT[pos]).value();
  else return NULL;            // k not in hash table
}
