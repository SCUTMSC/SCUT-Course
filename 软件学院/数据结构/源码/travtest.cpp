// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This program tests the relative efficiency for a number of
// preorder traversal implementations. 

#include "book.h"

#include "bnadt.h"

// Binary tree node class implementation
template <typename E>
class BinNodePtr : public BinNode<E> {
public:
  E it;                     // The node's value
  BinNodePtr* lc;              // Pointer to left child
  BinNodePtr* rc;              // Pointer to right child
public:
  // Two constructors -- with and without initial values
  BinNodePtr() { lc = rc = NULL; }
  BinNodePtr(E e, BinNodePtr* l =NULL,
                     BinNodePtr* r =NULL)
    { it = e; lc = l; rc = r; }
  ~BinNodePtr() {}             // Destructor
  E& val() { return it; }
  void setVal(const E& e) { it = e; }
  BinNode<E>* left() const { return lc; }
  void setLeft(BinNode<E>* b) { lc = (BinNodePtr*)b; }
  BinNode<E>* right() const { return rc; }
  void setRight(BinNode<E>* b) { rc = (BinNodePtr*)b; }
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};


// Binary tree class
template <typename E>
class bintree {
private:
  BinNode<E>* root;   // Root of the BST
public:
  bintree() { root = NULL; }  // Constructor
  BinNode<E>* getroot() { return root; }
  void setroot(BinNode<E>* newroot) { root = newroot; }
};


// Now we define several versions of preorder to test

// This implementation uses "check ahead" to call on children only
// if they are non-NULL. It uses access functions to get the children.
template <typename E>
void preorder1(BinNode<E>* root)
{
  if (root->left() != NULL) preorder1(root->left());
  if (root->right() != NULL) preorder1(root->right());
}

// This implementation uses "check ahead" to call on children only
// if they are non-NULL. It looks directly at the child pointers.
template <typename E>
void preorder1a(BinNodePtr<E>* root)
{
  if (root->lc != NULL) preorder1a(root->lc);
  if (root->rc != NULL) preorder1a(root->rc);
}

// This implementation uses "check ahead" to call on children only
// if they are non-NULL. It avoids making 2 calls to the child
// access functions by calling it once and storing the result.
template <typename E>
void preorder1b(BinNodePtr<E>* root)
{
  BinNodePtr<E>* myl = root->lc;
  BinNodePtr<E>* myr = root->rc;
  if (myl != NULL) preorder1b(myl);
  if (myr != NULL) preorder1b(myr);
}

// This implementation uses "check ahead" to call on children only
// if they are non-NULL. However, it also does a check on the
// root first, to protect against an initial call on an empty tree.
// This means that all of the checks on children on essentially redundant.
// Thus, it measures the extra cost by checking each pointer twice.
template <typename E>
void preorder2(BinNode<E>* root)
{
  if (root == NULL) return;  // Empty subtree, do nothing
  if (root->left() != NULL) preorder2(root->left());
  if (root->right() != NULL) preorder2(root->right());
}


// This implementation checks to see if the current node is NULL,
// but does not check the children. This results in recursive calls
// made on null children (effectively doubling the number of recursive
// calls). This version uses access functions to the children.
template <typename E>
void preorder3(BinNode<E>* root)
{
  if (root == NULL) return;  // Empty subtree, do nothing
  preorder3(root->left());
  preorder3(root->right());
}

// This implementation checks to see if the current node is NULL,
// but does not check the children. This results in recursive calls
// made on null children (effectively doubling the number of recursive
// calls). This version directly accesses the child pointers.
template <typename E>
void preorder3a(BinNodePtr<E>* root)
{
  if (root == NULL) return;  // Empty subtree, do nothing
  preorder3a(root->lc);
  preorder3a(root->rc);
}


/// Insert a node into a random spot in a binary tree.
template <typename E>
BinNode<E>* insert(BinNode<E>* root, E val) {
  if (root == NULL)
    return new BinNodePtr<E>(val);
  else if (Random(2) == 0) {
    root->setLeft(insert(root->left(), val));
    return root;
  }
  else {
    root->setRight(insert(root->right(), val));
    return root;
  }
}


// Build a random binary tree with "numnodes" nodes
template <typename E>
void buildRandomTree(int numnodes, bintree<E>* tree) {
  for(int i=0; i<numnodes; i++)
    tree->setroot(insert(tree->getroot(), i));
}


// Driver for preorder traversal timing tests
int main(int argc, char** argv) {
  bintree<int>* tree = new bintree<int>();

  Assert(argc == 3, "Usage: travtest <numnodes> <numruns>");

  int numnodes = atoi(argv[1]);
  int numruns = atoi(argv[2]);
  int i;
  Randomize();
  cout << "Build a tree with " << numnodes << " nodes\n";
  buildRandomTree(numnodes, tree);

  Settime();
  for (i=0; i<numruns; i++)
    preorder1(tree->getroot());
  cout << "Time for check-ahead (preorder1): "
	   << Gettime() << " sec\n";

  Settime();
  for (i=0; i<numruns; i++)
    preorder1a((BinNodePtr<int>*)tree->getroot());
  cout << "Time for stripped check-ahead (preorder1a): "
       << Gettime() << " sec\n";

  Settime();
  for (i=0; i<numruns; i++)
    preorder1b((BinNodePtr<int>*)tree->getroot());
  cout << "Time for prestored check-ahead (preorder1b): "
       << Gettime() << " sec\n";

  Settime();
  for (i=0; i<numruns; i++)
    preorder2(tree->getroot());
  cout << "Time for check-ahead with extra check (preorder2): "
       << Gettime() << " sec\n";

  Settime();
  for (i=0; i< numruns; i++)
    preorder3(tree->getroot());
  cout << "Time for pre-check with extra recursive calls (preorder3): "
       << Gettime() << " sec\n";

  Settime();
  for (i=0; i< numruns; i++)
    preorder3a((BinNodePtr<int>*)tree->getroot());
  cout << "Time for stripped pre-check with extra recursive calls (preorder3a): "
       << Gettime() << " sec\n";

  return 0;
}
