#include "headers.h"
#include "tree.h"
#include "utils.h"

using namespace std;

typedef GenericTreeNode<int> TreeNode;

/*
 *   1
 *  / \
 * 2   3
 *  \
 *   4
 *
 * [1,2,3,null,4,null,null]
 */
string serialize(TreeNode* root) {
    if (root == NULL) return "[]";
    string res = "";
    queue<TreeNode*> queue;
    queue.push(root);
    TreeNode* cur = NULL;
    res += '[';
    while (!queue.empty()) {
        cur = queue.front();
        queue.pop();
        res += cur == NULL ? "null" : to_string(cur->val);
        res += ',';
        if (cur != NULL) {
            queue.push(cur->left);
            queue.push(cur->right);
            cur->left = NULL;
            cur->right = NULL;
        }
    }
    res[res.length() - 1] = ']';
    return res;
}


/*
 *
 */
TreeNode* deserialize(string s) {
    if (s == "[]") return NULL;
    vector<string> node_strs = str_split(s.substr(1, s.length() - 2), ',');
    vector<TreeNode*> nodes(node_strs.size(), NULL);
    for (int i = 0; i < node_strs.size(); i++) {
        if (node_strs[i] != "null") {
            nodes[i] = new TreeNode(stoi(node_strs[i]));
        }
    }
    int i = 0, j = 1;
    while (j < nodes.size()) {
        nodes[i]->left = nodes[j++];
        nodes[i++]->right = nodes[j++];
        while (nodes[i] == NULL) i++;
    }
    return nodes[0];
}

