// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"

// gentree.h can't actually be included, unless we want to give the
// abstract class a name separate from what is being used here for
// the concrete class, and make the abstract class virtual.
// I just include this to indicate the relationship.
// For the book code, we don't want to show an implementation at this
// point, thus the existence of the fake "include" file gentree.h
// #include "gentree.h"


// Here is an implementation for a general tree, using the
// "left child/right sibling" implementation.

template <typename E>
class GTNode {
private:
  E element;
  GTNode<E>* rent;
  GTNode<E>* leftchild;
  GTNode<E>* rightsib;

public:
  GTNode(const E& value) { // Constructor
    rent = leftchild = rightsib = NULL;
    element = value;
  }

  GTNode(const E& value, GTNode<E>* par,
         GTNode<E>* leftc, GTNode<E>* rights) { // Constructor
    element = value;
    rent = par; leftchild = leftc; rightsib = rights;
  }  

  ~GTNode() {}                     // Destructor

  E value() { return element; } // Return node's value

  bool isLeaf()                    // True if node is a leaf
    { return leftchild == NULL; }

  GTNode* parent()                 // Return node's parent
    { return rent; }

  GTNode* leftmostChild()         // Return node's first child
    { return leftchild; }

  GTNode* rightSibling()          // Return node's right sibling
    { return rightsib; }

  void setValue(E&)             // Set node's value
    { element = value; }

  void insertFirst(GTNode<E>* n) { // Insert as the first child
    n->rightsib = leftchild;
    n->rent = this;
    leftchild = n;
  }

  void insertNext(GTNode<E>* n) {  // Insert as the right sibling
    n->rightsib = rightsib;
    n->rent = rent;
    rightsib = n;
  }

  void removeFirst() {            // Remove first child from tree
    if (leftchild == NULL) return;
    GTNode<E>* temp = leftchild;
    leftchild = leftchild->rightsib;
    delete temp;  // BAD -- lose all its subtree!
  }

  void removeNext() {             // Remove right sibling from tree
    if (rightsib == NULL) return;
    GTNode<E>* temp = rightsib;
    rightsib = rightsib->rightsib;
    delete temp;  // BAD -- lose all its subtree!
  }
};


/////////////////////////////////////////////

template <typename E>
class GenTree {
private:
  GTNode<E>* rt;
// Print using a preorder traversal
void printhelp(GTNode<E>* root) {
  if (root->isLeaf()) cout << "Leaf: ";
  else cout << "Internal: ";
  cout << root->value() << "\n";
  // Now process the children of "root"
  for (GTNode<E>* temp = root->leftmostChild();
       temp != NULL; temp = temp->rightSibling())
    printhelp(temp);
}

public:
  GenTree() { rt = NULL; }          // Constructor

  // AWFUL! Throw away the storage
  ~GenTree() { rt = NULL; }         // Destructor

  // AWFUL! Throw away the storage
  void clear() { rt = NULL; }       // Send all nodes to free store

  // Return the root of the tree
  GTNode<E>* root() { return rt; }

  // Combine two trees
  void newroot(const E& value, GTNode<E>* first,
                                  GTNode<E>* sib) {
    clear();
    rt = new GTNode<E>(value, (GTNode<E>*)NULL, first, sib);
  }

  void print() { printhelp(rt); }   // Print a tree
};



// Driver for testing the general tree implementation
int main() {
  GenTree<int> tree;
  GTNode<int>* ptr;
  GenTree<int> tree2;
  GTNode<int>* ptr2;

  tree.newroot(1, NULL, NULL);
  ptr = tree.root();
  cout << "Print the tree with one node\n";
  tree.print();
  ptr->insertFirst(new GTNode<int>(2));
  cout << "Print the tree with two nodes\n";
  tree.print();
  ptr = ptr->leftmostChild();
  cout << "ptr now at node " << ptr->value() << "\n";
  ptr->insertNext(new GTNode<int>(3));
  cout << "Print the tree with three nodes\n";
  tree.print();
  ptr->insertNext(new GTNode<int>(4));
  cout << "Print the tree with four nodes\n";
  tree.print();
  ptr = ptr->rightSibling();
  cout << "ptr now at node " << ptr->value() << "\n";
  ptr->insertFirst(new GTNode<int>(5));
  cout << "Print the tree with 5 nodes\n";
  tree.print();

  tree2.newroot(11, NULL, NULL);
  ptr2 = tree2.root();
  ptr2->insertFirst(new GTNode<int>(12));
  ptr2 = ptr2->leftmostChild();
  ptr2->insertNext(new GTNode<int>(13));

  return 0;
}
