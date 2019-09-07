// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple external merge demonstration.
// First in a series of three programs.
// This version implements a standard 2-way mergsort on an external file. 
// Runs start at length 1 and double each time until the file is sorted.
// This program only works if the number of records is a power of 2.

#include <fstream>
#include <cstdio>

using std::fstream;
using std::ifstream;
using std::ios;

#include "book.h"

// Return 2^x
int pow2(int x) {
  int val = 1;
  for (int i=0; i<x; i++)
    val *= 2;
  return val;
}

#define RecsPerBlock 1024  // Number of records/block

// Define indices for run files.
// These indices get swapped around as necessary to switch input files
// to become output files on alternate passes.
#define IN 0
#define IN1 0
#define IN2 1
#define OUT 2
#define OUT1 2
#define OUT2 3

// Records are simply a 4 byte quantity, 2 bytes for key and 2 bytes for data.
typedef int E;

// Maintain info on the run files -- two input files, two output files
// Posit indicates the current position in the given file
int Posit[4];
// Buffers for the four run files
E Array[4][RecsPerBlock];
// File pointers for the four run files
fstream FS[4];
// Names of the four run files
char Name[4][30];

int readcnt = 0;  // Count of number of blocks read
int writecnt = 0; // Count of number of blocks written

// Return in val the next record from the file fpindex.
// This supports buffered reading from the input file, one block at a time.
void getnext(int fpindex, E& val) {
  if (Posit[fpindex] >= RecsPerBlock) { // page fault
    FS[fpindex].read((char*)&Array[fpindex], sizeof(E)*RecsPerBlock);
    if (!FS[fpindex]) {
      cout << "Error reading file!\n";
      cout << readcnt << " blocks were read, and " << writecnt
           << " blocks were written\n";
      exit(-1);
    }
    readcnt++;
    Posit[fpindex] = 0;
  }
  val = Array[fpindex][Posit[fpindex]++];
}


// Write a record (in val) to the output file fpindex.
// This supports buffered writing to the output file, one block at a time.
void putout(int fpindex, E val) {
  Array[fpindex][Posit[fpindex]++] = val;
  if (Posit[fpindex] == RecsPerBlock) { // page fault
    FS[fpindex].write((char*)Array[fpindex], sizeof(E)*RecsPerBlock);
    writecnt++;
    Posit[fpindex] = 0;
  }
}


// First pass of merge sort.
// Split input into two files.
void pass1(int inindex, int outindex1, int outindex2, int numrecs)
{
  E val;

  Posit[inindex] = RecsPerBlock; // Prime a read
  for (int i=0; i<numrecs; i++) {
    getnext(inindex, val);
    if(ODD(i))
      putout(outindex2, val);
    else
      putout(outindex1, val);
  }
}


// Do the real work here
void exmergesort(int in1, int in2, int out1, int out2, char* outname,
                 int numrecs) {
  E val1, val2;

  // Open output files
  FS[OUT1].open(Name[OUT1], ios::out | ios::binary);
  if (!FS[OUT1]) cout << "Error opening " << Name[OUT1] << endl;
  FS[OUT2].open(Name[OUT2], ios::out | ios::binary);
  if (!FS[OUT2]) cout << "Error opening " << Name[OUT2] << endl;

  // Create the initial run files
  pass1(in1, out1, out2, numrecs);
cout << "Done pass1\n";

  FS[in1].clear();  FS[in1].close();
  FS[out1].clear(); FS[out1].close();
  FS[out2].clear(); FS[out2].close();


  // Now, merge runs into two output files.
  // Repeat that process until only one run is left.

  // Compute the number of passes that will be needed
  int numpass = 0;
  for (int i=1; i<numrecs; i=i*2)
     numpass++;

  // Now do the passes
  cout << "Now we will do " << numpass << " passes\n";
  for(int i=0; i<numpass; i++) { // For each pass
    int passrecs = pow2(i); // Number of records/run this pass
    int numruns = numrecs/(passrecs*2); // Number of runs this pass

    swap(in1, out1);
    swap(in2, out2);
    FS[in1].open(Name[in1], ios::in | ios::binary);
    if (!FS[in1]) cout << "Error opening " << Name[in1] << endl;
    FS[in2].open(Name[in2], ios::in | ios::binary);
    if (!FS[in2]) cout << "Error opening " << Name[in2] << endl;
    FS[out1].open(Name[out1], ios::out | ios::binary);
    if (!FS[out1]) cout << "Error opening " << Name[out1] << endl;
    FS[out2].open(Name[out2], ios::out | ios::binary);
    if (!FS[out2]) cout << "Error opening " << Name[out2] << endl;

    Posit[out1] = Posit[out2] = 0;
    Posit[in1] = Posit[in2] = RecsPerBlock; // Prime a read

    for (int j=0; j<numruns; j++) { // For each run this pass
      int count1 = 1;  int count2 = 1; // Records read from each run
      getnext(in1, val1); getnext(in2, val2);
      for (int k=0; k<(passrecs*2); k++) { 
	if (count1 > passrecs) { // exhausted first run
          putout(out1, val2);
          count2++;
          if (count2 <= passrecs) getnext(in2, val2);
        }
        else if (count2 > passrecs) { // exhausted second run
          putout(out1, val1);
          count1++;
          if (count1 <= passrecs) getnext(in1, val1);
        }
        else // Got records from each run still
        if (val1 < val2) {
          putout(out1, val1);
          count1++;
          if (count1 <= passrecs) getnext(in1, val1);
        }
        else {
          putout(out1, val2);
          count2++;
          if (count2 <= passrecs) getnext(in2, val2);
        }
      }
      swap(out1, out2);
    }
    // Done this pass, so flush output
    FS[in1].clear(); FS[in1].close();
    FS[in2].clear(); FS[in2].close();
    FS[out1].clear(); FS[out1].close();
    FS[out2].clear(); FS[out2].close();
  }
  rename(Name[out2], outname);
}


// Main routine.  Get everything ready
int main(int argc, char** argv) {

  if (argc != 3) {
    cout << "Usage: exmrg1 <infile> <outfile>.\n";
    exit(-1);
  }

  // Check the file size. It must be a multiple of the block size,
  // and a power of 2.
  long size;
  ifstream file (argv[1], ios::in|ios::binary);
  file.seekg (0, ios::end);
  size = file.tellg();
  file.close();
  cout << "size of " << argv[1];
  cout << " is " << size << " bytes.\n";
  if ((size % (sizeof(E)*RecsPerBlock)) != 0) {
    cout << "Error. File size must be a multiple of the block size.\n";
    exit(-1);
  }
  int numrecs = size/sizeof(E);
  int i;
  for (i=1; i<numrecs; i*=2);
  if (i != numrecs) {
    cout << "Error. File size must be a power of 2.\n";
    exit(-1);
  }

  // For first pass, need the original input file.  Won't use again
  FS[IN1].open(argv[1], ios::in | ios::binary);
  if (!FS[IN1]) cout << "Error opening " << argv[1] << endl;

  // build the names of the run files
  sprintf(Name[IN1], "%s%s", argv[1], ".1");
  sprintf(Name[IN2], "%s%s", argv[1], ".2");
  sprintf(Name[OUT1], "%s%s", argv[2], ".1");
  sprintf(Name[OUT2], "%s%s", argv[2], ".2");

  // Start timing from here
  Settime();
  exmergesort(IN1, IN2, OUT1, OUT2, argv[2], size/sizeof(E));
  cout << "Time is " << Gettime() << "seconds\n";

  cout << readcnt << " blocks were read, and " << writecnt
       << " blocks were written\n";
  return 0;
}
