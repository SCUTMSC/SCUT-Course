// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Floyd's all-pairs shortest paths algorithm.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"

#include "grlist.h"

int **D;

// Floyd's all-pairs shortest paths algorithm
// Store the pair-wise distances in "D"
void Floyd(Graph* G) {
  for (int i=0; i<G->n(); i++) // Initialize D with weights
    for (int j=0; j<G->n(); j++)
      if (G->weight(i, j) != 0) D[i][j] = G->weight(i, j);
  for (int k=0; k<G->n(); k++) // Compute all k paths
    for (int i=0; i<G->n(); i++)
      for (int j=0; j<G->n(); j++)
        if (D[i][j] > (D[i][k] + D[k][j]))
          D[i][j] = D[i][k] + D[k][j];
}


// Test Floyd's all-pairs shortest paths algorithm
// Version for Adjancency Matrix representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;
  int i,j;

  if (argc != 2) {
    cout << "Usage: grfloydl <file>\n";
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

  D  = new int*[G->n()];
  for (i=0; i<G->n(); i++)
    D[i] = new int[G->n()];
  for (i=0; i<G->n(); i++)
    for (j=0; j<G->n(); j++)
      D[i][j] = INFINITY;
  for (i=0; i<G->n(); i++)
    D[i][i] = 0;

  Floyd(G);
  for (i=0; i<G->n(); i++) {
    for (j=0; j<G->n(); j++)
      if (D[i][j] == INFINITY)
        cout << "-1 ";
      else
	cout << D[i][j] << " ";
    cout << endl;
  }
  return 0;
}
