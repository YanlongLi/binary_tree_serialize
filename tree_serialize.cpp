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

/*
 *        1
 *       / \
 *      2   3
 *         /
 *        4
 *
 * "1,2,#,#,3,4,#,#,#"
 */
string _serialize_postorder(TreeNode* node) {
    if (node == NULL) return "#";
    return to_string(node->val) + "," + _serialize_postorder(node->left) + "," + _serialize_postorder(node->right);
}

string serialize_postorder(TreeNode* node) {
    if (node == NULL) return "";
    return _serialize_postorder(node);
}

TreeNode* _deserialize_postorder(const vector<TreeNode*>& nodes, int& i) {
    TreeNode* cur = nodes[i++];
    if (cur != NULL) {
        cur->left = _deserialize_postorder(nodes, i);
        cur->right = _deserialize_postorder(nodes, i);
    }
}

TreeNode* deserialize_postorder(string s) {
    if (s.length() == 0) return NULL;
    vector<string> str_nodes = str_split(s, ',');
    vector<TreeNode*> nodes(str_nodes.size(), NULL);
    for (int i = 0; i < str_nodes.size(); i++) {
        if (str_nodes[i] != "#") {
            nodes[i] = new TreeNode(stoi(str_nodes[i]));
        }
    }
    int i = 0;
    return _deserialize_postorder(nodes, i);
}
