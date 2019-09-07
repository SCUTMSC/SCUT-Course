// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Kruskal's MCST algroithm.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency Matrix representation

#include "book.h"

#define ROOT -1

// Include support for UNION/FIND
#include "uf.h"

#include "grmat.h"

// Use a Priority Queue to get next cheapest edge
#include "heap.h"

int minVertex(Graph*, int*);

void AddEdgetoMST(int v1, int v2) {
  cout << "Add edge " << v1 << " to " << v2 << "\n";
}

// Simple class to store data in the heap: edge and its distance
class KruskElem {         // An element for the heap
public:
  int from, to, distance; // The edge being stored
  KruskElem() { from = -1;  to = -1; distance = -1; }
  KruskElem(int f, int t, int d)
    { from = f; to = t; distance = d; }
};

// Comparator to compare two KruskElem's
class Comp {
public:
  static bool prior(KruskElem x, KruskElem y)
    { return x.distance < y.distance; }
};

void Kruskel(Graph* G) {   // Kruskal's MST algorithm
  ParPtrTree A(G->n());    // Equivalence class array
  KruskElem E[G->e()];     // Array of edges for min-heap
  int i;
  int edgecnt = 0;
  for (i=0; i<G->n(); i++) // Put the edges on the array
    for (int w=G->first(i); w<G->n(); w = G->next(i,w)) {
      E[edgecnt].distance = G->weight(i, w);
      E[edgecnt].from = i;
      E[edgecnt++].to = w;
    }
  // Heapify the edges
  heap<KruskElem, Comp> H(E, edgecnt, edgecnt);
  int numMST = G->n();       // Initially n equiv classes
  for (i=0; numMST>1; i++) { // Combine equiv classes
    KruskElem temp;
    temp = H.removefirst(); // Get next cheapest edge
    int v = temp.from;  int u = temp.to;
    if (A.differ(v, u)) {  // If in different equiv classes
      A.UNION(v, u);       // Combine equiv classes
      AddEdgetoMST(temp.from, temp.to);  // Add edge to MST
      numMST--;            // One less MST
    }
  }
}


// Test Kruskal's MCST algorithm
// Version for Adjancency Matrix representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: gkruskm <file>\n";
    exit(-1);
  }

  if ((fid = fopen(argv[1], "rt")) == NULL) {
    cout << "Unable to open file |" << argv[1] << "|\n";
    exit(-1);
  }

  G = createGraph<Graphm>(fid);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  Kruskel(G);
  return 0;
}
