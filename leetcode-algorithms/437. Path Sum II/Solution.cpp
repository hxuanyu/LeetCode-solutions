// You are given a binary tree in which each node contains an integer value.
//
// Find the number of paths that sum to a given value.
//
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
// Example:
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
//
// Return 3. The paths that sum to 8 are:
//
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11
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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        else if ((root->left == nullptr) && (root->right == nullptr)) return sum == root->val ? 1 : 0;
        travel(root, sum);
        return total;
    }

    void travel(TreeNode* root, int sum) {
        if (root == nullptr) return;


        int left = getnumof(root->left, sum - root->val);
        int right = getnumof(root->right, sum - root->val);
        total += root->val == sum ? 1 : 0;
        total += (left + right);
        travel(root->left, sum);
        travel(root->right, sum);
    }

    int getnumof(TreeNode* node, int total) {
        if (node == nullptr) return 0;

        int v = 0;
        if (node->val == total) v += 1;
        v += getnumof(node->left, total - node->val);
        v += getnumof(node->right, total - node->val);

        return v;
    }

    int total = 0;

};
