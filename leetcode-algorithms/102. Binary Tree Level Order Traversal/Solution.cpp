// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> vmap;

        travel(root, 0, vmap);

        vector<vector<int>> rslt;
        for (auto v : vmap) {
            rslt.push_back(v.second);
        }
        return rslt;
    }

    void travel(TreeNode* node, int level, map<int, vector<int>>& vmap) {
        if (node == nullptr) return;

        if (!vmap.count(level)) {
            vector<int> v = {node->val};
            vmap[level] = v;
        } else vmap[level].push_back(node->val);

        travel(node->left, level + 1, vmap);
        travel(node->right, level + 1, vmap);
    }
};
