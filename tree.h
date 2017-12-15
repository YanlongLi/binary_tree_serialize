/* =============================================================================
#     FileName: tree.h
#         Desc:
#       Author: YanlongLi
#        Email: lansunlong@gmail.com
#     HomePage:
#      Created: 2017-12-15 09:22:33
#      Version: 0.0.1
#   LastChange: 2017-12-15 09:22:33
#      History:
#               0.0.1 | YanlongLi | init
============================================================================= */
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
