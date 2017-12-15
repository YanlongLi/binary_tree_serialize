#ifndef TREE_SERIALIZE_H_QZINCPW6
#define TREE_SERIALIZE_H_QZINCPW6

#include "headers.h"
#include "tree.h"

using namespace std;

typedef GenericTreeNode<int> TreeNode;

string serialize(TreeNode* root);
string str_join(const vector<string>& vec, char c);
vector<string> str_split(const string& s, char c);
TreeNode* deserialize(string s);

#endif /* end of include guard: TREE_SERIALIZE_H_QZINCPW6 */
