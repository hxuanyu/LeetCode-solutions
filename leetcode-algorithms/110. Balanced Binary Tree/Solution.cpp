// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        depmap[nullptr] = 0;
        getdepth(root);

        bool balanced = true;
        travel(root, balanced);
        return balanced;
    }

    int getdepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int depth = max(getdepth(root->left), getdepth(root->right)) + 1;
        depmap[root] = depth;
        return depth;
    }

    void travel(TreeNode* root, bool& balanced) {
        if (root == nullptr) return;
        if (!balanced) return;

        balanced = abs(depmap[root->right] - depmap[root->left]) <= 1;

        travel(root->left, balanced);
        travel(root->right, balanced);
    }
    map<TreeNode*, int> depmap;
};
