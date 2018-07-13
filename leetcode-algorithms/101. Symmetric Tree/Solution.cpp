// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* a, TreeNode* b) {
        if ((a == nullptr) && (b == nullptr)) return true;
        else if ((a != nullptr) && (b != nullptr)) {
            return (a->val == b->val) && isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left);
        } else return false;

    }
};
