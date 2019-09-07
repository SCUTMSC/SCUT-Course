// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Program to find connected components in a graph

#include "book.h"

#include "grmat.h"

void DFS_component(Graph* G, int v, int component) {
  G->setMark(v, component);
  for (int w=G->first(v); w<G->n(); w = G->next(v,w))
    if (G->getMark(w) == 0)
      DFS_component(G, w, component);
}

void concom(Graph* G) {
  int i;
  int component = 1;   // Counter for current component
  for (i=0; i<G->n(); i++) // For n vertices in graph
    G->setMark(i, 0); // Vertices start in no component
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == 0) // Start a new component
      DFS_component(G, i, component++);
}


// Find connected components in a graph
// Version for Adjancency Matrix representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: grconcomm <file>\n";
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

  concom(G);

  for (int i=0; i<G->n(); i++)
    cout << "Vertex " << i << ": " << G->getMark(i) << endl;
  return 0;
}
