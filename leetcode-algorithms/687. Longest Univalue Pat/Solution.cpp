// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
// Example 1:
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:
//
// 2
// Example 2:
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:
//
// 2
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
//
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
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        else if ((root->left == nullptr) && (root->right == nullptr)) return 0;

        travel(root);
        return maxcount - 1;
    }

    void travel(TreeNode* root) {
        if (root == nullptr) return;
        int left = getlen(root->left, root->val);
        int right = getlen(root->right, root->val);
        int v = 1 + left + right;
        maxcount = max(maxcount, v);
        travel(root->left);
        travel(root->right);
    }

    int getlen(TreeNode* root, int val) {
        if ((root == nullptr) || (root->val != val)) return 0;

        int left = getlen(root->left, val);
        int right = getlen(root->right, val);
        return 1 + max(left, right);
    }

    int maxcount = 0;
};
