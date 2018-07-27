// Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
//
//
//
// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
//
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
//
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
//
//
//
// Note:
//
// Both of the given trees will have between 1 and 100 nodes.
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        travel(root1, a);
        travel(root2, b);
        return a == b;
    }

    void travel(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        else if ((root->left == nullptr) && (root->right == nullptr)) vec.push_back(root->val);

        travel(root->left, vec);
        travel(root->right, vec);
    }
};
