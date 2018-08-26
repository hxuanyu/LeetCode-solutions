// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        travel(root, 0);
        vector<int> rslt;
        for (auto item : vmap) rslt.push_back(item.second);
        return rslt;
    }

    void travel(TreeNode* root, int level) {
        if (root == nullptr) return;
        if (vmap.count(level) == 0) vmap[level] = root->val;
        travel(root->right, level + 1);
        travel(root->left, level + 1);
    }
    map<int, int> vmap;
};
