// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// k-d tree class
template <typename E> class KD {
private:
  BinNode<E>* root;
  int D;                 // Dimension of the key
  int nodecount;         // Number of nodes in the KD tree

  // Private "helper" functions

  // Return true iff the two points are within radius distance of each other
  bool InCircle(int* c1, int* c2, int radius) const {
    int total = 0;
    for (int i=0; i<D; i++) // Compute sum of squares
      total += (c1[i]-c2[i]) * (c1[i]-c2[i]);
    return (total <= (radius*radius));
  }

  // True iff two coords are equal
  bool EqualCoord(const int* a, const int* b) const {
    for (int i=0; i<D; i++)
      if (a[i] != b[i]) return false;
    return true;
  }

  // Return the node with the smaller value for this discrim
  BinNode<E>* min(BinNode<E>* node1,
                     BinNode<E>* node2, int discrim) const {
    if (node1 == NULL) return node2;
    if (node2 == NULL) return node1;
    if (((node2->val())->coord())[discrim] <
        ((node1->val())->coord())[discrim])
      return node2;
    else return node1;
  }

  // Clean up the KD tree by releasing space back free store
  void clearhelp(BinNode<E>* root) {
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
  }

  // Insert a node into the KD tree, returning the updated tree
  BinNode<E>* inserthelp(BinNode<E>* root,
                            const E& it, int discrim) {
    if (root == NULL)  // Empty tree: create node
      return (new BSTNode<int,E>(0, it, NULL, NULL));
    if (((root->val())->coord())[discrim] > (it->coord())[discrim])
      root->setLeft(inserthelp(root->left(), it, (discrim+1)%D));
    else root->setRight(inserthelp(root->right(), it, (discrim+1)%D));
    return root;       // Return tree with node inserted
  }

// Find the record with the given coordinates
bool findhelp(BinNode<E>* root, int* coord,
              E& e, int discrim) const {
  // Member "coord" of a node is an integer array storing
  // the node's coordinates.
  if (root == NULL) return false;     // Empty tree
  int* currcoord = (root->val())->coord();
  if (EqualCoord(currcoord, coord)) { // Found it
    e = root->val();
    return true;
  }
  if (currcoord[discrim] < coord[discrim])
    return findhelp(root->left(),coord,e,(discrim+1)%D);
  else
    return findhelp(root->right(),coord,e,(discrim+1)%D);
}
// Print all points within distance "rad" of "coord"
void regionhelp(BinNode<E>* root, int* coord,
                int rad, int discrim) const {
  if (root == NULL) return;       // Empty tree
  // Check if record at root is in circle
  if (InCircle((root->val())->coord(), coord, rad))
    cout << root->val() << endl;  // Do what is appropriate
  int* currcoord = (root->val())->coord();
  if (currcoord[discrim] > (coord[discrim] - rad))
    regionhelp(root->left(), coord, rad, (discrim+1)%D);
  if (currcoord[discrim] < (coord[discrim] + rad))
    regionhelp(root->right(), coord, rad, (discrim+1)%D);
}
// Return a pointer to the node with the least value in root
// for the selected descriminator
BinNode<E>* findmin(BinNode<E>* root,
                       int discrim, int currdis) const {
  // discrim: discriminator key used for minimum search;
  // currdis: current level (mod D);
  if (root == NULL) return NULL;
  BinNode<E> *minnode = findmin(root->left(), discrim,
                                   (currdis+1)%D);
  if (discrim != currdis) { // If not at descrim's level,
                            // we must search both subtrees
    BinNode<E> *rightmin =
        findmin(root->right(), discrim, (currdis+1)%D);
    // Check if right side has smaller key value
    minnode = min(minnode, rightmin, discrim);
  } // Now, minnode has the smallest value in children
  return min(minnode, root, discrim);
}

  // Return in R the element (if any) which matches the coordinates K.
  // Return the updated subtree with R removed from the tree.
  BinNode<E>* removehelp(BinNode<E>* root, const int* K,
                            BinNode<E>*& R, int descrim) {
    if (root == NULL) return NULL; // K is not in tree
    int* currcoord = (root->val())->coord();
    if (!EqualCoord(currcoord, K)) { // Continue searching
      if (K[descrim] < currcoord[descrim])
        root->setLeft(removehelp(root->left(), K, R, (descrim+1)%D));
      else root->setRight(removehelp(root->right(), K, R, (descrim+1)%D));
    }
    else {                            // Found K: remove this node
      R = root;
      if (root->right() == NULL) {    // No right child
        root->setRight(root->left()); //  so move left child to right
        root->setLeft(NULL);          // And make left NULL
      }
      if (root->right() == NULL)      // Both children are emtpy
        return NULL;                  // So the root will become NULL
      else {                          // Replace root with min on right
        BinNode<E>* temp;
        // First, find the min on right side
        temp = findmin(root->right(), descrim, (descrim+1)%D);
        // Now, actually get that min node out of the right side
        root->setRight(removehelp(root->right(),
                       (temp->val())->coord(), temp, (descrim+1)%D));
        // At this point, we hold the minimum node, and the children are correct
        // So just replace root with the minimum and return the old root
        E te = root->val();
        root->setVal(temp->val());
        temp->setVal(te);
        R = temp;
      }
    }
    return root;
  }

  // Print out a KD tree in preorder
  void printhelp(BinNode<E>* root, int level) const {
    if (root == NULL) { // Empty tree
      cout << " NULL";
      return;
    }
    // Print node value
    cout << endl;
    for (int i=0; i<level; i++)         // Indent to level
      cout << "  ";
    cout << root->val();

    // Print children
    printhelp(root->left(), level+1);   // Do left subtree
    printhelp(root->right(), level+1);  // Do right subtree
  }


public:
  // Constructor
  KD(int Din) { root = NULL; D = Din; nodecount = 0;}

  void insert(const E& it) {
    root = inserthelp(root, it, 0);
    nodecount++;
  }

  void clear()
    { clearhelp(root); root = NULL; nodecount = 0; }

  void remove(int* coord, E& it) {
    BinNode<E>* t = NULL;
    root = removehelp(root, coord, t, 0);
    if (t != NULL) {
      it = t->val();
      nodecount--;
      delete t;
    }
  }

  bool find(E& e, int* coord) const
    { return findhelp(root, coord, e, 0); }

  void regionsearch(int* coord, int radius) const {
    regionhelp(root, coord, radius, 0);
  }

  int size() { return nodecount; }

  void print() const {
    if (root == NULL) cout << "The kd-tree is empty.\n";
    else {
      printhelp(root, 0);
      cout << endl;
    }
  }
};
