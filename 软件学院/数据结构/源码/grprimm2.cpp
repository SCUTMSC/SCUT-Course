// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Prim's MCST algroithm. This version uses
// a priority queue to find the next closest vertex,
// similar to the second version of Dijkstra's algorithm
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency Matrix representation

#include "book.h"

#include "grmat.h"
#include "heap.h"

int minVertex(Graph*, int*);

void AddEdgetoMST(int v1, int v2) {
  cout << "Add edge " << v1 << " to " << v2 << "\n";
}

class DijkElem {
public:
  int vertex, distance;
  DijkElem() { vertex = -1; distance = -1; }
  DijkElem(int v, int d) { vertex = v; distance = d; }
};

// Comparator class for comparing DijkElem's
class DDComp {
public:
  static bool prior(DijkElem x, DijkElem y)
    { return x.distance < y.distance; }
};

// Prim's MST algorithm: priority queue version
void Prim(Graph* G, int* D, int s) {
  int i, v, w;           // "v" is current vertex
  int V[G->n()];         // V[I] stores I's closest neighbor
  DijkElem temp;
  DijkElem E[G->e()];    // Heap array with lots of space
  temp.distance = 0; temp.vertex = s;
  E[0] = temp;           // Initialize heap array
  heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap
  for (i=0; i<G->n(); i++) {           // Now build MST
    do {
      if(H.size() == 0) return; // Nothing to remove
      temp = H.removefirst();
      v = temp.vertex;
    } while (G->getMark(v) == VISITED);
    G->setMark(v, VISITED);
    if (v != s) AddEdgetoMST(V[v], v); // Add edge to MST
    if (D[v] == INFINITY) return;      // Ureachable vertex
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > G->weight(v, w)) {    // Update D
        D[w] = G->weight(v, w);
        V[w] = v;        // Update who it came from
        temp.distance = D[w]; temp.vertex = w;
        H.insert(temp);  // Insert new distance in heap
      }
  }
}


// Prim's MCST algorithm: use priority queue
// Version for Adjancency Matrix representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: grprimm2 <file>\n";
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

  int D[G->n()];
  for (int i=0; i<G->n(); i++)     // Initialize
    D[i] = INFINITY;
  D[0] = 0;

  Prim(G, D, 0);
  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;
  return 0;
}
