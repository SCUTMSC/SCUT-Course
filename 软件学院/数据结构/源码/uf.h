// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// General tree representation for UNION/FIND
class ParPtrTree {
private:
  int* array;                    // Node array
  int size;                      // Size of node array
  int FIND(int) const;           // Find root
public:
  ParPtrTree(int);                   // Constructor
  ~ParPtrTree() { delete [] array; } // Destructor
  void UNION(int, int);          // Merge equivalences
  bool differ(int, int);         // True if not in same tree
};
ParPtrTree::ParPtrTree(int sz) { // Constructor
  size = sz;
  array = new int[sz];           // Create node array
  for(int i=0; i<sz; i++) array[i] = ROOT;
}

// Return True if nodes are in different trees
bool ParPtrTree::differ(int a, int b) {
  int root1 = FIND(a);           // Find root of node a
  int root2 = FIND(b);           // Find root of node b
  return root1 != root2;         // Compare roots
}

void ParPtrTree::UNION(int a, int b) { // Merge subtrees
  int root1 = FIND(a);           // Find root of node a
  int root2 = FIND(b);           // Find root of node b
  if (root1 != root2) array[root2] = root1; // Merge
}
// FIND with path compression
int ParPtrTree::FIND(int curr) const {
  if (array[curr] == ROOT) return curr; // At root
  array[curr] = FIND(array[curr]);
  return array[curr];
}

