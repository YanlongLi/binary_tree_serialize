#ifndef TREE_SERIALIZE_H_QZINCPW6
#define TREE_SERIALIZE_H_QZINCPW6

#include "headers.h"
#include "tree.h"

using namespace std;

typedef GenericTreeNode<int> TreeNode;

string serialize(TreeNode* root);
TreeNode* deserialize(string s);

string serialize_postorder(TreeNode* node);
TreeNode* deserialize_postorder(string s);

#endif /* end of include guard: TREE_SERIALIZE_H_QZINCPW6 */
