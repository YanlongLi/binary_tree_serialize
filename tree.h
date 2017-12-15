#ifndef TREE_H_69ZH3XBP
#define TREE_H_69ZH3XBP

#include <iostream>

template<class T>
struct GenericTreeNode {
    T val;
    GenericTreeNode<T> *left;
    GenericTreeNode<T> *right;
    GenericTreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

#endif /* end of include guard: TREE_H_69ZH3XBP */
