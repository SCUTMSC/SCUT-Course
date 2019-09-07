// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test driver for syntax checking the various hashing routines

#include "book.h"

// Include comparator functions
#include "compare.h"

#define HASHSIZE 101

int HT[HASHSIZE];
int M = HASHSIZE;

// Hash function for character strings.
// Use folding on a string, summed 4 bytes at a time
int sfold(char* key) {
  unsigned int *lkey = (unsigned int *)key;
  int intlength = strlen(key)/4;
  unsigned int sum = 0;
  for(int i=0; i<intlength; i++)
    sum += lkey[i];

  // Now deal with the extra chars at the end
  int extra = strlen(key) - intlength*4;
  char temp[4];
  lkey = (unsigned int *)temp;
  lkey[0] = 0;
  for(int i=0; i<extra; i++)
    temp[i] = key[intlength*4+i];
  sum += lkey[0];

  return sum % M;
}

// Hash function for character strings:
// Simply sum up the ascii values per character
int h(char* x) {
  int i, sum;
  for (sum=0, i=0; x[i] != '\0'; i++)
    sum += (int) x[i];
  return sum % M;
}

// Hash function for ints: take mod 16
int h(int x) {
  return x % 16;
}

template <typename Key>
int p(Key K, int i) { return i; }

int main(int argc, char** argv) {
  if (argc == 2)
    cout << "Hashed |" << argv[1] << "| to " << sfold(argv[1]) << endl;

  cout << "Sfold on aaaabbbb returns " << sfold("aaaabbbb") << endl;
  return 0;
}
