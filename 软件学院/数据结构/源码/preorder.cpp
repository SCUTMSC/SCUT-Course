// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for various preorder traversals of a binary tree.
// This includes two implementations for preorder traversal,
// and a traversal that counts the number of nodes in the tree.

#include "book.h"

#include "BSTNode.h"

// Stick these in to test the preorder routine
#define visit(X) (cout << X->element() << endl)

// This is the preferred structure for preorder traversal.
// It tests the pointer to the current node before visiting it,
// but does not test that children are NULL before calling a
// visit on them. This version does not rely on the caller
// to test the root for safety.
template <typename E>
void preorder(BinNode<E>* root) {
  if (root == NULL) return; // Empty subtree, do nothing
  visit(root);              // Perform desired action
  preorder(root->left());
  preorder(root->right());
}

// Count the number of nodes in a binary tree
template <typename E>
int count(BinNode<E>* root) {
  if (root == NULL) return 0;  // Nothing to count
  return 1 + count(root->left())
           + count(root->right());
}

// Verify that this is a BST
template <typename Key, typename E>
bool checkBST(BSTNode<Key,E>* root, Key low, Key high) {
  if (root == NULL) return true; // Empty subtree
  Key rootkey = root->key();
  if ((rootkey < low) || (rootkey > high))
    return false; // Out of range
  if (!checkBST<Key,E>(root->left(), low, rootkey))
    return false; // Left side failed
  return checkBST<Key,E>(root->right(), rootkey, high);
}

// This version of preorder does "look ahead" to test if
// a child should be visited before doing the visit.
// This requires an external test of the root to make it safe
// from calls on an empty tree.
template <typename E>
void preorder2(BinNode<E>* root) {
  visit(root);  // Perform whatever action is desired
  if (root->left() != NULL) preorder2(root->left());
  if (root->right() != NULL) preorder2(root->right());
}

int main()
{
  BSTNode<int,Int>* root = new BSTNode<int,Int>(10,10);
  root->setLeft(new BSTNode<int,Int>(15,15));
  root->setRight(new BSTNode<int,Int>(20,20));
  preorder(root);
  cout << " Count is: " << count(root) << endl;
  preorder2(root);

  if (checkBST<int,Int>(root, -1, 1000))
    cout << "Yes, its a BST\n";
  else cout << "No, it is not a BST\n";

  BSTNode<int,int>* root2 = new BSTNode<int,int>(10,10);
  root2->setLeft(new BSTNode<int,int>(5,5));
  root2->setRight(new BSTNode<int,int>(20,20));
  preorder(root2);
  cout << " Count is: " << count(root2) << endl;
  preorder2(root2);

  if (checkBST<int,int>(root2, -1, 1000))
    cout << "Yes, its a BST\n";
  else cout << "No, it is not a BST\n";
}
