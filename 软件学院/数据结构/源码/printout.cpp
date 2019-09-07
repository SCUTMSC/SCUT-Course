// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A simple program to print out some data from a (presumably) sorted file.
// The program prints the first record from each block of 4096 bytes.
// A record is assumed to have a two-byte key value and a two-byte data value.
// It prints 8 records per line.
// It also prints the time required to run the program.

#include "book.h"

#include <fstream>

using std::fstream;
using std::ios;

// A block is 4096 bytes, or 1024 logical records
#define NumRec 1024

typedef short E;

int main(int argc, char** argv) {
  int filesize; // Number of blocks printed, from commmandline argument
  E Array[NumRec*2]; // Each record is a key and data field
  fstream myfile;

  clock_t start = clock();
  if (argc < 3) {
    cout << "Usage: printout <filename> <size>\n";
    cout << "Size is measured in blocks of 4096 bytes.\n";
    exit(-1);
  }

  myfile.open(argv[1], ios::in | ios::binary);
  if (!myfile) {
    cout << "Unable to open file :" << argv[1] << ":\n";
    exit(-1);
  }
  filesize = atoi(argv[2]);

  for (int count=0; count<filesize; count++) {
    myfile.read((char*)Array, sizeof(E) * NumRec * 2);
    cout << Array[0] << " " << Array[1];
    if ((count != 0) && (((count+1) % 8) == 0)) cout << endl;
    else cout << "  ";
  }

  cout << endl;
  clock_t end = clock();
  cout << (double)((double)end - (double)start)/
          (double)CLOCKS_PER_SEC << " seconds\n";
}
