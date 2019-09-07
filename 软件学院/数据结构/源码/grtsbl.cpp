// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Topological Sort using BFS (queue)
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"

#include "grlist.h"

#include "aqueue.h"

void printout(int v) {
  cout << v << " ";
}

// Topological sort: Queue
void topsort(Graph* G, Queue<int>* Q) {
  int Count[G->n()];
  int v, w;
  for (v=0; v<G->n(); v++) Count[v] = 0; // Initialize
  for (v=0; v<G->n(); v++)   // Process every edge
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
       Count[w]++;           // Add to v2's prereq count
  for (v=0; v<G->n(); v++)   // Initialize queue
    if (Count[v] == 0)       // Vertex has no prerequisites
      Q->enqueue(v);
  while (Q->length() != 0) { // Process the vertices
    v = Q->dequeue();
    printout(v);             // PreVisit for "v"
    for (w=G->first(v); w<G->n(); w = G->next(v,w)) {
      Count[w]--;            // One less prerequisite
      if (Count[w] == 0)     // This vertex is now free
        Q->enqueue(w);
    }
  }
}


// Test Topological Sort with BFS (queue)
// Version for Adjancency List representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: grdfsm <file>\n";
    exit(-1);
  }

  if ((fid = fopen(argv[1], "rt")) == NULL) {
    cout << "Unable to open file |" << argv[1] << "|\n";
    exit(-1);
  }

  G = createGraph<Graphl>(fid);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  Queue<int>* Q = new AQueue<int>(G->n());

  topsort(G, Q);
  cout << endl;
  return 0;
}
