// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Print out a 2-3 Tree
template <typename Key, typename E>
void TTTree<Key, E>::
printhelp(TTNode<Key,E>* rt, int level) const {
  if (rt == NULL) return;
  for (int i=0; i<level; i++) cout << "   "; // indent
  cout << rt->lval;
  if (rt->rkey != EMPTYKEY)
    cout << "  " << rt->rval << "\n";
  else cout << "\n";
  printhelp(rt->left, level+1);
  printhelp(rt->center, level+1);
  if (rt->rkey != EMPTYKEY)
    printhelp(rt->right, level+1);
}
