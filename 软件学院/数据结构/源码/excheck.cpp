// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Check to see that the contents of a file are sorted.
// Records are assumed to consist of two short values, with the first
// short being the key and the second being the data field.
// All key values are assumed to be positive. The file is checked to see
// that the records are sorted from lowest to highest. Duplicates are
// permitted.

#include <fstream>

using std::fstream;
using std::ifstream;
using std::ios;

#include "book.h"

#define RecsPerBlock 1024 // Number of records/block
#define BlockSize (RecsPerBlock*sizeof(E)*2) // Size of a block, in bytes

typedef unsigned short E; // A record is two "E"s

int main(int argc, char** argv) {

  if (argc < 2) {
    cout << "Usage: excheck <file>\n";
    exit(-1);
  }

  // Check the file size. It must be a multiple of the block size.
  long l,m;
  ifstream file (argv[1], ios::in|ios::binary);
  if (!file) {
    cout << "Error opening " << argv[1] << endl;
    exit(-1);
  }
  l = file.tellg();
  file.seekg(0, ios::end);
  m = file.tellg();
  int size = m-l;
  int numblocks = size/BlockSize;
  cout << "The size of " << argv[1] << " is " << (m-l)
       << " bytes, which is " << numblocks << " blocks\n";
  if ((size % BlockSize) != 0) {
    cout << "Error. File size must be a multiple of the block size.\n";
    exit(-1);
  }

  file.seekg(0); // Seek back to the start of the file
  E *buffer = new E[RecsPerBlock*2];

  E currval = 0;
  for (int i=0; i<numblocks; i++) {
    file.read((char*)buffer, BlockSize);
    for (int j=0; j<RecsPerBlock; j++) {
      if (currval > buffer[j*2]) {
        cout << "This file is not sorted\n";
        cout << "Check failed on block " << i << ", record " << j << endl;
        cout << "The values were " << currval << " and "
             << buffer[j*2] << endl;
        exit(-1);
      }
      currval = buffer[j*2];
    }
  }
  cout << "This file is sorted\n";
}
