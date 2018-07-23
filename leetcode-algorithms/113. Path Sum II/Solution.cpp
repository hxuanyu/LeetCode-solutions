// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<TreeNode*>> rslt;
        vector<TreeNode*> temp;

        perm(root, sum, temp, rslt);

        vector<vector<int>> rslt1;
        for (auto v : rslt) {
            vector<int> local;
            for (auto node : v) {
                local.push_back(node->val);
            }
            rslt1.push_back(local);
        }

        return rslt1;
    }

    void perm(TreeNode* root, int sum, vector<TreeNode*>& temp, vector<vector<TreeNode*>>& rslt) {
        if (root == nullptr) return;
        else if ((root->left == nullptr) && (root->right == nullptr)) {
            int total = root->val;
            for (auto v : temp) total += v->val;
            if (total == sum) {
                temp.push_back(root);
                rslt.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        temp.push_back(root);
        perm(root->left, sum, temp, rslt);
        perm(root->right, sum, temp, rslt);
        temp.pop_back();
    }
};
