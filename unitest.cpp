/* =============================================================================
#     FileName: unitest.cpp
#         Desc:
#       Author: YanlongLi
#        Email: lansunlong@gmail.com
#     HomePage:
#      Created: 2017-12-15 09:24:01
#      Version: 0.0.1
#   LastChange: 2017-12-15 09:24:01
#      History:
#               0.0.1 | YanlongLi | init
============================================================================= */
#include "headers.h"
#include "tree.h"
#include "tree_serialize.h"
#include "utils.h"

#include "gtest/gtest.h"

using namespace std;
/*
 *
 */
TEST(StrJoin, StrJoin) {
    EXPECT_EQ("", str_join({}, ','));
    EXPECT_EQ("1,2,3", str_join({"1", "2", "3"}, ','));
}

/*
 *
 */
TEST(StrSplitTest, StrSplit) {
    EXPECT_EQ(0, str_split("", ',').size());
    EXPECT_EQ(3, str_split("1,2,3", ',').size());
    EXPECT_EQ(3, str_split(",1,2,3", ',').size());
    EXPECT_EQ(3, str_split("1,2,3,", ',').size());
    EXPECT_EQ(3, str_split("1,,2,,3,", ',').size());
}

/*
 *
 */

bool tree_equal(TreeNode* node1, TreeNode* node2) {
    if (node1 == NULL && node2 == NULL) return true;
    if (node1 != NULL && node2 == NULL) return false;
    if (node1 == NULL && node2 != NULL) return false;
    if (node1->val != node2->val) return false;
    return tree_equal(node1->left, node2->left) && tree_equal(node1->right, node2->right);
}

void delete_node(TreeNode* node) {
    if (node == NULL) return;
    if (node->left != NULL) delete_node(node->left);
    if (node->right != NULL) delete_node(node->right);
    delete node;
}

TEST(TreeSerializeTest, SerializeNull) {
    EXPECT_EQ("[]", serialize(NULL));
}

TEST(TreeSerializeTest, SerializeTree) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;

    string s = "[1,2,3,null,null,4,null,null,null]";
    TreeNode* new_root = deserialize(s);

    EXPECT_EQ(s, serialize(node1));
    EXPECT_EQ(s, serialize(new_root));
    EXPECT_EQ(true, tree_equal(node1, new_root));

    delete_node(node1);
    delete_node(new_root);
}

/*
 *
 */
TEST(TreeSerializeTest, SerializeTreePostorderNULL) {
    EXPECT_EQ("", serialize_postorder(NULL));
    EXPECT_EQ(NULL, deserialize_postorder(""));
}

TEST(TreeSerializeTest, SerializeTreePostorder) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;

    string s =  "1,2,#,#,3,4,#,#,#";
    TreeNode* new_root = deserialize_postorder(s);
    EXPECT_EQ(s, serialize_postorder(node1));
    EXPECT_EQ(true, tree_equal(node1, new_root));

    delete_node(node1);
}

/*
 *
 */
TEST(TreeDeserializeTest, DeSerializeTree) {
    string s = "[1,2,3,null,null,4,null,null,null]";
    TreeNode* root = deserialize(s);
    EXPECT_EQ(s, serialize(root));

    delete_node(root);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    if (RUN_ALL_TESTS() != 0) {
        cout << "Run TEST faile";
    }
    return 0;
}
