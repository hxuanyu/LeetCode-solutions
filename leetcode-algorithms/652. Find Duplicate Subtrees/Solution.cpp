// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node values.
//
// Example 1:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:
//
//       2
//      /
//     4
// and
//
//     4
// Therefore, you need to return above trees' root in the form of a list.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> rslt;
        travel(root);

        for (auto item : vmap) {
            if (item.second.size() > 1) rslt.push_back(*(item.second.begin()));
        }

        return rslt;
    }

    string travel(TreeNode* root) {
        if (root == nullptr) return "#!";

        string sval = std::to_string(root->val) + "!" + travel(root->left) + travel(root->right);
        vmap[sval].insert(root);
        return sval;
    }
    map<string, set<TreeNode*>> vmap;
};
