// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"

int main(int argc, char** argv)
{
  if (argc != 3) {
    cout << "Usage: hashsim <#_of_records> <#_of_iterations>\n";
    return -1;
  }

  int recs = atoi(argv[1]);
  int iterations = atoi(argv[2]);

  srand(1);

  int hashtable[2*recs];  // This is the pseudo hash table, twice the # of records

  // Data collecting variables
  int maxlen = 0;   // Maximum length of any chain, ever
  int avglen = 0;   // Average for the maximum (per iteration) chain length
  int minslots = (2*recs); // Minimum slots used by any interation
  int avgslots = 0; // Average number of slots used per iteration

  for(int i=0; i<iterations; i++) {
    int j;
    int slots = 0;
    int len = 0;

    // Intialize the table for this iteration
    for (j=0; j<(2*recs); j++) hashtable[j] = 0;

    // "insert" records into the hash table
    for (j=0; j<recs; j++) {
      int homeslot = rand() % (2*recs);
if (homeslot > (2*recs)) cout << "ERROR\n";
      hashtable[homeslot]++; // Imagine that we are inserting here, bump the count
    }

    // Update the statistics
    for (j=0; j<(2*recs); j++) {
      if (hashtable[j] > maxlen) maxlen = hashtable[j]; // longest chain ever
      if (hashtable[j] > len) len = hashtable[j];  // longest chain this iteration
      if (hashtable[j] > 0) slots++; // Something hit this slot
    }
    if (slots < minslots) minslots = slots;
    avglen += len;
    avgslots += slots;
  }

  // Calculate the final statistics
  cout << "For " << iterations << " iterations on " << recs << " records\n";
  cout << "The longest chain ever generated was " << maxlen << endl;
  cout << "The average length for the maximum chain was " 
       << ((double)avglen)/((double)iterations) << endl;
  cout << "The minimum number of slots ever used was " << minslots << endl;
  cout << "The average number of slots used was "
       << ((double)avgslots)/((double)iterations) << endl;
  return 0;
}
