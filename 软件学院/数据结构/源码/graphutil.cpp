// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Functions for creating and printing graphs

#define LINELEN 80

void Gprint(Graph* G) {
  int i, j;

  cout << "Number of vertices is " << G->n() << "\n";
  cout << "Number of edges is " << G->e() << "\n";

  cout << "Matrix is:\n";
  for (i=0; i<G->n(); i++) {
    for(j=0; j<G->n(); j++)
      cout << G->weight(i, j) << " ";
    cout << "\n";
  }
}


char* getl(char* buffer, int n, FILE* fid) {
  char* ptr;
  ptr = fgets(buffer, n, fid);
  while ((ptr != NULL) && (buffer[0] == '#'))
    ptr = fgets(buffer, n, fid);
  return ptr;
}


// Create a graph from file fid
template <typename GType>
Graph* createGraph(FILE* fid) {
  char buffer[LINELEN+1]; // Line buffer for reading
  bool undirected;  // true if graph is undirected, false if directed
  int i;
  int v1, v2, dist;

  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get number of vertices
{ cout << "Unable to read number of vertices\n";
    return NULL;
}

  Graph* G = new GType(atoi(buffer));

  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get graph type
{ cout << "Unable to read graph type\n";
    return NULL ;
}
  if (buffer[0] == 'U')
    undirected = true;
  else if (buffer[0] == 'D')
    undirected = false;
  else {
    cout << "Bad graph type: |" << buffer << "|\n";
    return NULL;
  }

  // Read in edges
  while (getl(buffer, LINELEN, fid) != NULL) {
    v1 = atoi(buffer);
    i = 0;
    while (isdigit(buffer[i])) i++;
    while (buffer[i] == ' ') i++;
    v2 = atoi(&buffer[i]);
    while (isdigit(buffer[i])) i++;
    if (buffer[i] == ' ') { // There is a distance
      while (buffer[i] == ' ') i++;
      dist = atoi(&buffer[i]);
    }
    else dist = 1;
    G->setEdge(v1, v2, dist);
    if (undirected) // Put in edge in other direction
      G->setEdge(v2, v1, dist);
  }
  return G;
}
