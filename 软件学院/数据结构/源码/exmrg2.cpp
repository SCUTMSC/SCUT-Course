// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple external merge demonstration.
// Second in a series of three programs.
// This version implements a standard 2-way mergsort on an external file
// like exmrg1, except that it begins by building a large initial run
// using quicksort (specifically, qsort2 in this distribution, the version
// that does a quicksort on lists of length <= THRESHOLD).
// After the initial run has been created (with working memory size
// determined by a command line parameter), a series of two-way merge
// passes is used to combine the runs together.

#include <fstream>

using std::fstream;
using std::ifstream;
using std::ios;

#include "book.h"

// Include comparator functions
#include "compare.h"

const int THRESHOLD=0;

// Insertion sort for final cleanup sort pass
template <typename E, typename Comp>
void inssort(E A[], int n) { // Insertion Sort
  for (int i=1; i<n; i++)       // Insert i'th record
    for (int j=i; (j>0) && (Comp::prior(A[j], A[j-1])); j--)
      swap(A, j, j-1);
}

// Simple findpivot: Pick middle value in array
template <typename E>
inline int findpivot(E A[], int i, int j)
  { return (i+j)/2; }

// Partition the array
template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
  do {             // Move the bounds inward until they meet
    while (Comp::prior(A[++l], pivot));  // Move l right and
    while ((l < r) && Comp::prior(pivot, A[--r])); // r left
    swap(A, l, r);              // Swap out-of-place values
  } while (l < r);              // Stop when they cross
  return l;      // Return first position in right partition
}

// qsort core function: do not qsort lists of length <= THRESHOLD
template <typename E, typename Comp>
void qsort(E array[], int i, int j) {
  if ((j-i) <= THRESHOLD) return; // Don't sort short list
  int pivotindex = findpivot(array, i, j);
  swap(array, pivotindex, j); // stick pivot at end
  int k = partition<E,Comp>(array, i-1, j, array[j]);
  swap(array, k, j);          // Put pivot value in place
  qsort<E,Comp>(array, i, k-1);
  qsort<E,Comp>(array, k+1, j);
}

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
      cout << "Error reading file " << Name[fpindex] << endl;
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

void sort(E* array, int n) {
  qsort<E,minintCompare>(array, 0, n-1);
  inssort<E,minintCompare>(array, n); // Cleanup sort
}

// First pass of merge sort.
// Split input into two files.
void pass1(int inindex, int outindex1, int outindex2, int numruns,
           E* BigArray, int memsize)
{
  int memblocks = memsize/(sizeof(E) * RecsPerBlock);

  for (int i=0; i<numruns; i++) {
    FS[inindex].read((char*)BigArray, memsize);
    readcnt += memblocks;
    if (!FS[inindex]) cout << "Error reading run " << i << endl;

    sort(BigArray, memsize/sizeof(E));

    FS[outindex1].write((char*)BigArray, memsize);
    writecnt += memblocks;
    if (!FS[outindex1]) cout << "Error writing run " << i << endl;
    swap(outindex1, outindex2); // Alternate between the output files
  }
}


// Do the real work here
void exmergesort(int in1, int in2, int out1, int out2, char* outname,
                 int numrecs, int memsize) {
  E val1, val2;

  // Open output files
  FS[OUT1].open(Name[OUT1], ios::out | ios::binary);
  if (!FS[OUT1]) cout << "Error opening " << Name[OUT1] << endl;
  FS[OUT2].open(Name[OUT2], ios::out | ios::binary);
  if (!FS[OUT2]) cout << "Error opening " << Name[OUT2] << endl;

  // Allocate the memory pool
  E *mempool = new E[memsize/sizeof(E)];

  int numruns = (numrecs*sizeof(E))/memsize;
  if ((numrecs*(int)sizeof(E)) < memsize)
    numruns = 1;
  // Create the initial run files
  pass1(in1, out1, out2, numruns, mempool, memsize);
cout << "Done pass1\n";

  FS[in1].clear();  FS[in1].close();
  FS[out1].clear(); FS[out1].close();
  FS[out2].clear(); FS[out2].close();


  // Now, merge runs into two output files.
  // Repeat that process until only one run is left.

  // Compute the number of passes that will be needed
  int numpass = 0;
  for (int i=numruns; i>1; i=i/2)
     numpass++;

  // Now do the passes
  cout << "Now we will do " << numpass << " passes\n";
  for(int i=0; i<numpass; i++) { // For each pass
    int passrecs = numrecs/numruns; // Number of records/run this pass
    cout << "Do Pass " << i << " on " << numruns << " runs each with "
         << passrecs << " records\n";

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

    for (int j=0; j<(numruns/2); j++) { // For each run this pass
      int count1 = 1;  int count2 = 1; // Records read from each run
      getnext(in1, val1); getnext(in2, val2);
      for (int k=0; k<(2*passrecs); k++) { 
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
    numruns = numruns/2; // Ready for next pass
  }
  rename(Name[out2], outname);
}


// Main routine.  Get everything ready
int main(int argc, char** argv) {

  if (argc != 4) {
    cout << "Usage: exmrg2 <infile> <outfile> <memsize>.\n";
    cout << "Numblocks is the size of the file in blocks.\n";
    cout << "Blocksize is " << RecsPerBlock * sizeof(E) << " bytes.\n";
    cout << "Memsize is the size of working memory, measured in blocks.\n";
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

  int memblocks = atoi(argv[3]);
  int memsize = memblocks * RecsPerBlock * sizeof(E);
  if (size < memsize) memsize = size;
  if ((size % memsize) != 0) {
    cout << "Error: File size must be a multiple of the working memory\n";
    exit(-1);
  }
  cout << "Allocating " << memsize << " bytes of working space\n";

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
  exmergesort(IN1, IN2, OUT1, OUT2, argv[2], size/sizeof(E), memsize);
  cout << "Time is " << Gettime() << "seconds\n";

  cout << readcnt << " blocks were read, and " << writecnt
       << " blocks were written\n";
  return 0;
}
