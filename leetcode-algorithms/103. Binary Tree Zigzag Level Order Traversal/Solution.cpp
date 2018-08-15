// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rslt;
        travel(root, 0, rslt);

        for (int i = 0; i < rslt.size(); i++) {
            if (i % 2) reverse(rslt[i].begin(), rslt[i].end());
        }
        return rslt;
    }

    void travel(TreeNode* node, int level, vector<vector<int>>& rslt) {
        if (node == nullptr) return;
        if (rslt.size() == level) {
            vector<int> v = {node->val};
            rslt.push_back(v);
        } else {
            rslt[level].push_back(node->val);
        }

        travel(node->left, level + 1, rslt);
        travel(node->right, level + 1, rslt);
    }
};
