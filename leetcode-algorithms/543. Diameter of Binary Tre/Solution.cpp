// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
// Example:
// Given a binary tree
//           1
//          / \
//         2   3
//        / \
//       4   5
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
// Note: The length of path between two nodes is represented by the number of edges between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxv = 0;
        getMaxlen(root, maxv);
        return maxv;
    }

    int getMaxlen(TreeNode* node, int& maxv) {
        if (node == nullptr) return 0;
        else if ((node->left == nullptr) && (node->right == nullptr)) return 1;

        if (maxlen.count(node)) return maxlen[node];
        int left = getMaxlen(node->left, maxv);
        int right = getMaxlen(node->right, maxv);

        maxv = max(maxv, left + right);
        maxlen[node] = 1 + max(left, right);
        return maxlen[node];
    }

    map<TreeNode*, int> maxlen;
};
