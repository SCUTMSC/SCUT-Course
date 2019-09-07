// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file gathers together all of the pieces of the 2-3 Tree implementation

#include "dictionary.h"

// Empty key value
int EMPTYKEY = -1;

#include "ttnode.h"

#include "tttree.h"

#include "ttprint.h"

template <typename Key, typename E>
TTNode<Key,E>* TTTree<Key, E>::
inserthelp(TTNode<Key,E>* rt, const Key k, const E e) {
  TTNode<Key,E>* retval;
  if (rt == NULL) // Empty tree: create a leaf node for root
    return new TTNode<Key,E>(k, e, EMPTYKEY, NULL,
                             NULL, NULL, NULL);
  if (rt->isLeaf()) // At leaf node: insert here
    return rt->add(new TTNode<Key,E>(k, e, EMPTYKEY, NULL,
                                     NULL, NULL, NULL));
  // Add to internal node
  if (k < rt->lkey) {
    retval = inserthelp(rt->left, k, e);
    if (retval == rt->left) return rt;
    else return rt->add(retval);
  }
  else if((rt->rkey == EMPTYKEY) || (k < rt->rkey)) {
    retval = inserthelp(rt->center, k, e);
    if (retval == rt->center) return rt;
    else return rt->add(retval);
  }
  else { // Insert right
    retval = inserthelp(rt->right, k, e);
    if (retval == rt->right) return rt;
    else return rt->add(retval);
  }
}

// Add a new key/value pair to the node. There might be a
// subtree associated with the record being added. This
// information comes in the form of a 2-3 tree node with
// one key and a (possibly NULL) subtree through the
// center pointer field.
template <typename Key, typename E>
TTNode<Key,E>* TTNode<Key, E>::add(TTNode<Key,E>* it) {
  if (rkey == EMPTYKEY) { // Only one key, add here
    if (lkey < it->lkey) {
      rkey = it->lkey; rval = it->lval;
      right = center; center = it->center;
    }
    else {
      rkey = lkey; rval = lval; right = center;
      lkey = it->lkey; lval = it->lval;
      center = it->center;
    }
    return this;
  }
  else if (lkey >= it->lkey) { // Add left
    center = new TTNode<Key,E>(rkey, rval, EMPTYKEY, NULL,
                                center, right, NULL);
    rkey = EMPTYKEY; rval = NULL; right = NULL;
    it->left = left; left = it;
    return this;
  }
  else if (rkey < it->lkey) { // Add center
    it->center = new TTNode<Key,E>(rkey, rval, EMPTYKEY,
                            NULL, it->center, right, NULL);
    it->left = this;
    rkey = EMPTYKEY; rval = NULL; right = NULL;
    return it;
  }
  else { // Add right
    TTNode<Key,E>* N1 = new TTNode<Key,E>(rkey, rval,
                           EMPTYKEY, NULL, this, it, NULL);
    it->left = right;
    right = NULL; rkey = EMPTYKEY; rval = NULL;
    return N1;
  }
}

// Find the record that matches a given key value
template <typename Key, typename E>
E TTTree<Key, E>::
findhelp(TTNode<Key,E>* root, Key k) const {
  if (root == NULL) return NULL;         // value not found
  if (k == root->lkey) return root->lval;
  if (k == root->rkey) return root->rval;
  if (k < root->lkey)                       // Go left
    return findhelp(root->left, k);
  else if (root->rkey == EMPTYKEY)          // 2 child node
    return findhelp(root->center, k);       // Go center
  else if (k < root->rkey)
    return findhelp(root->center, k);       // Go center
  else return findhelp(root->right, k);     // Go right
}
