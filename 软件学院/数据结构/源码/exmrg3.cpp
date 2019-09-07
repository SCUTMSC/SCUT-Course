// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple external merge demonstration.
// Third in a series of three programs.
// This version implements a k-way mergsort on an external file.
// Like exmrg2 it begins by building a large initial run using quicksort.
// After the initial run has been created (with working memory size
// determined by a command line parameter), a series of k-way merge
// passes is used to combine the runs together.

#include <fstream>

using std::fstream;
using std::ifstream;
using std::ios;

#include "book.h"

#define BIGKEY 600000000L // HACK!!

#include "compare.h"

const int THRESHOLD=0;
template <typename E, typename Comp>
void inssort(E A[], int n) { // Insertion Sort
  for (int i=1; i<n; i++)       // Insert i'th record
    for (int j=i; (j>0) && (Comp::prior(A[j], A[j-1])); j--)
      swap(A, j, j-1);
}
template <typename E>
inline int findpivot(E A[], int i, int j)
  { return (i+j)/2; }
template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
  do {             // Move the bounds inward until they meet
    while (Comp::prior(A[++l], pivot));  // Move l right and
    while ((l < r) && Comp::prior(pivot, A[--r])); // r left
    swap(A, l, r);              // Swap out-of-place values
  } while (l < r);              // Stop when they cross
  return l;      // Return first position in right partition
}
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

int readcnt = 0;  // Count of number of blocks read
int writecnt = 0; // Count of number of blocks written

void sort(E* array, int n) {
  qsort<E,minintCompare>(array, 0, n-1);
  inssort<E,minintCompare>(array, n); // Cleanup sort
}

// First pass of merge sort.
// Split input into two files.
void pass1(char* inname, int numruns, E* BigArray, int memsize)
{
  int memblocks = memsize/(sizeof(E) * RecsPerBlock);

  fstream infile;
  fstream outfile;
  infile.open(inname, ios::in | ios::binary);
  if (!infile) cout << "Error opening " << infile << endl;
  outfile.open("temp", ios::out | ios::binary);
  if (!outfile) cout << "Error opening " << "temp" << endl;

  for (int i=0; i<numruns; i++) {
    infile.read((char*)BigArray, memsize);
    readcnt += memblocks;
    if (!infile) cout << "Error reading run " << i << endl;

    sort(BigArray, memsize/sizeof(E));

    outfile.write((char*)BigArray, memsize);
    writecnt += memblocks;
    if (!outfile) cout << "Error writing run " << i << endl;
  }
  infile.close();
  outfile.close();
}


// Return index of run with the least value from the current candidates
inline int getleast(E* mempool, int* Posit, int numblocks) {
  E temp = BIGKEY; // Initially some value that is bigger than any key
  int index = -1;

  for (int i=0; i<numblocks; i++) {
    if ((Posit[i] != RecsPerBlock) &&
        (mempool[i*RecsPerBlock + Posit[i]] < temp)) {
      temp = mempool[i*RecsPerBlock + Posit[i]];
      index = i;
    }
  }
  return index;
}


// Update the run buffer that just got taken from
inline void getnext(int index, fstream& tempfile, int base,
             int* Posit, int* Count, E* mempool, int BlocksPerRun) {
  if (Posit[index] == (RecsPerBlock-1)) { // Page Fault
    if (Count[index] == (BlocksPerRun-1)) { // Already exhausted
      Posit[index]++;
      return;
    }
    // Read in a new block
    Count[index]++;
    tempfile.seekg(base + index*RecsPerBlock*BlocksPerRun*sizeof(E) +
                   Count[index]*RecsPerBlock*sizeof(E));
    tempfile.read((char*)&(mempool[index*RecsPerBlock]),
                  sizeof(E)*RecsPerBlock);
    readcnt++;
    Posit[index] = 0;
  }
  else Posit[index]++;
}

// Put a new value to the buffered output file
inline void putout(fstream& outfile, E* val) {
  static E OutBuff[RecsPerBlock];
  static int OutPos = 0;

  OutBuff[OutPos++] = val[0];
  if (OutPos == RecsPerBlock) { // page fault
    outfile.write((char*)OutBuff, sizeof(E)*RecsPerBlock);
    writecnt++;
    OutPos = 0;
  }
}

// Do the real work here
void exmergesort(char* inname, char* outname, int numrecs, int memsize) {
  fstream infile;
  fstream outfile;

  // Allocate the memory pool
  cout << "Allocating " << memsize << " bytes of working space\n";
  E *mempool = new E[memsize/sizeof(E)];

  int numruns = (numrecs*sizeof(E))/memsize;

  // Create the initial runs in the temp file
  pass1(inname, numruns, mempool, memsize);
  cout << "Done pass1 for runs of " << memsize/sizeof(E) << " records\n";

  // Now, merge runs with multiway merge.
  // Repeat that process until only one run is left.

  // Compute the number of passes that will be needed
  int numblocks = memsize/(sizeof(E)*RecsPerBlock);
  int numpass = 0;
  for (int i=numruns; i>1; i=i/numblocks)
     numpass++;

  // Now do the passes
  char* onename = "temp";
  char* twoname = outname;

  // Space to store the current run positions
  int* Posit = new int[numblocks]; // Which record of this block we are on
  int* Count = new int[numblocks]; // Which block of the run we are on

  for(int i=0; i<numpass; i++) { // For each pass
    int passrecs = numrecs/numruns; // Number of records/run this pass

    // Open the files
    infile.open(onename, ios::in | ios::binary);
    if (!infile) cout << "Error opening " << infile << endl;
    outfile.open(twoname, ios::out | ios::binary);
    if (!outfile) cout << "Error opening " << "temp" << endl;

    int BlocksPerRun = passrecs/RecsPerBlock;
    for(int j=0; j<(numruns/numblocks); j++) { // For each batch of runs
      int base = j*memsize*BlocksPerRun; // Base offset for this set of runs

      // Prime the buffers for reading
      for (int i=0; i<numblocks; i++) {
        Posit[i] = RecsPerBlock-1;  // Set this at the end to prime it.
        Count[i] = -1;
        getnext(i, infile, base, Posit, Count, mempool, BlocksPerRun);
      }

      int index;
      while ((index = getleast(mempool, Posit, numblocks)) != -1) {
        putout(outfile, &(mempool[index*RecsPerBlock + Posit[index]]));
        getnext(index, infile, base, Posit, Count, mempool, BlocksPerRun);
      }
    }
    // Prepare for next pass
    infile.close();
    outfile.close();
    swap(onename, twoname);
    numruns = numruns/numblocks;
  }
  if (EVEN(numpass))
    rename("temp", outname);
}


// Main routine.  Get everything ready
int main(int argc, char** argv) {
  int mycnt;

  if (argc != 4) {
    cout << "Usage: exmrg3 <infile> <outfile> <memsize>.\n";
    cout << "Numblocks is the size of the file in blocks.\n";
    cout << "Blocksize is " << RecsPerBlock * sizeof(E) << " bytes.\n";
    cout << "Memsize is the size of working memory, measured in blocks.\n";
    exit(-1);
  }

  // Check the file size. It must be a multiple of the block size.
  long size;
  ifstream file (argv[1], ios::in|ios::binary);
  file.seekg (0, ios::end);
  size = file.tellg();
  file.close();
  cout << "size of " << argv[1] << " is " << size << " bytes.\n";
  if ((size % (sizeof(E)*RecsPerBlock)) != 0) {
    cout << "Error. File size must be a multiple of the block size.\n";
    exit(-1);
  }

  // There must be at least two blocks in the working memory, and the
  // number of blocks in the file must be a power of the number of blocks
  // in the working memory.
  int numrecs = size/sizeof(E);
  int workingblocks = atoi(argv[3]);
  int memsize = workingblocks * RecsPerBlock * sizeof(E);
  if (workingblocks < 2) {
    cout << "Error: Working memory size must be at least two blocks\n";
    exit(-1);
  }
  if (size < memsize) memsize = size;
  int fileblocks = numrecs/RecsPerBlock;

  cout << "workingblocks is " << workingblocks
       << ", fileblocks is " << fileblocks << endl;
  for (mycnt=workingblocks; mycnt<fileblocks; mycnt*=workingblocks);
  if (mycnt != fileblocks) {
    cout << "Error: File size in blocks must be a power of the "
         << "working memory size\n";
    exit(-1);
  }

  // Start timing from here
  Settime();
  exmergesort(argv[1], argv[2], size/sizeof(E), memsize);
  cout << "Time is " << Gettime() << "seconds\n";

  cout << readcnt << " blocks were read, and " << writecnt
       << " blocks were written\n";
  return 0;
}
