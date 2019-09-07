// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Heap class
template <typename E, typename Comp> class heap {
private:
  E* Heap;          // Pointer to the heap array
  int maxsize;         // Maximum size of the heap
  int n;               // Number of elements now in the heap

  // Helper function to put element in its correct place
  void siftdown(int pos) {
    while (!isLeaf(pos)) { // Stop if pos is a leaf
      int j = leftchild(pos);  int rc = rightchild(pos);
      if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
        j = rc;            // Set j to greater child's value
      if (Comp::prior(Heap[pos], Heap[j])) return; // Done
      swap(Heap, pos, j);
      pos = j;             // Move down
    }
  }

public:
  heap(E* h, int num, int max)     // Constructor
    { Heap = h;  n = num;  maxsize = max;  buildHeap(); }
  int size() const       // Return current heap size
    { return n; }
  bool isLeaf(int pos) const // True if pos is a leaf
    { return (pos >= n/2) && (pos < n); }
  int leftchild(int pos) const
    { return 2*pos + 1; }    // Return leftchild position
  int rightchild(int pos) const
    { return 2*pos + 2; }    // Return rightchild position
  int parent(int pos) const  // Return parent position
    { return (pos-1)/2; }
  void buildHeap()           // Heapify contents of Heap
    { for (int i=n/2-1; i>=0; i--) siftdown(i); }

  // Insert "it" into the heap
  void insert(const E& it) {
    Assert(n < maxsize, "Heap is full");
    int curr = n++;
    Heap[curr] = it;            // Start at end of heap
    // Now sift up until curr's parent > curr
    while ((curr!=0) &&
           (Comp::prior(Heap[curr], Heap[parent(curr)]))) {
      swap(Heap, curr, parent(curr));
      curr = parent(curr);
    }
  }
  // Remove first value
  E removefirst() {
    Assert (n > 0, "Heap is empty");
    swap(Heap, 0, --n);       // Swap first with last value
    if (n != 0) siftdown(0);  // Siftdown new root val
    return Heap[n];             // Return deleted value
  }

  // Remove and return element at specified position
  E remove(int pos) {
    Assert((pos >= 0) && (pos < n), "Bad position");
    if (pos == (n-1)) n--; // Last element, no work to do
    else
    {
      swap(Heap, pos, --n);          // Swap with last value
      while ((pos != 0) &&
             (Comp::prior(Heap[pos], Heap[parent(pos)]))) {
        swap(Heap, pos, parent(pos)); // Push up large key
        pos = parent(pos);
      }
      if (n != 0) siftdown(pos);     // Push down small key
    }
    return Heap[n];
  }
};
