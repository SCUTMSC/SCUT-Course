// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program generates test files for external sorting algorithms.
// Output files can be of any multiple of the 4096 byte block size.
// The data records are logically a two byte (short int) key value followed
// by a two byte (short int) data value.
// The values output by this program can either be "binary" or "ascii".
// "Binary" files have key and data values each in the range 1 to 30,000.
// "Ascii" files have their data and key values selected so that they are
// easy to read and test. The data value prints in ascii as two spaces.
// The key value prints in ascii as a space and then a capital letter (A-Z).
// This makes it simple to tell if the sorting algorithm is working.

#include "book.h"

#include <fstream>
#include <string>
#include <cstring>

using std::fstream;
using std::ios;

// A block is 4096 bytes, or 1024 logical records
#define NumRec 1024

typedef int E;

int main(int argc, char** argv) {
  int filesize;
  E Array[NumRec];
  int i, j;
  fstream myfile;
  bool Ascii;        // True if ASCII option, false if binary option.

  if (argc < 4) {
    cout << "Usage: genfile <option> <filename> <size>\n";
    cout << "Size is measured in blocks of 4096 bytes.\n";
    cout << "Options must be '-a' for ASCII, or '-b' for binary.\n";
    cout << "ASCII files have a data value of 8224 (prints as 2 spaces)\n";
    cout << "and a key value between 8257 and 8282 (prints as a space\n";
    cout << "and a letter).\n";
    cout << "Binary files have key and data values between 1 and 30000\n";
    exit(-1);
  }

  if (!strcmp(argv[1], "-a"))
    Ascii = true;
  else if (!strcmp(argv[1], "-b"))
    Ascii = false;
  else {
    cout << "Illegal option '" << argv[1] << "'\n";
    cout << "Usage: genfile <option> <filename> <size>\n";
    exit(-1);
  }

  myfile.open(argv[2], ios::out | ios::binary);
  if (!myfile) {
    cout << "Unable to open file :" << argv[2] << ":\n";
    exit(-1);
  }
  filesize = atoi(argv[3]);

  Randomize();
  for (i=0; i<filesize; i++) { // For each block
    for (j=0; j<NumRec; j++)   // For each record
      if (Ascii)
        // A record has a 2-byte key that prints as <space><letter>
        // and a 2-byte value that prints as <space><space>
        Array[j] = (8224 << 16) + Random(26) + 0x2041;
      else // Keys and values in range 1 - 30,000.
        Array[j] = ((Random(29999) + 1) << 16) + ((Random(29999) + 1));
    myfile.write((char*)Array, sizeof(E) * NumRec);
  }
  return 0;
}
