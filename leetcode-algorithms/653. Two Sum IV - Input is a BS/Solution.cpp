// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
// Example 2:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        travel(root, vec);

        int a = 0;
        int b = vec.size() - 1;

        while (a < b) {
            int total = vec[a] + vec[b];
            if (total == k) return true;
            else if (total > k) b--;
            else a++;
        }

        return false;
    }

    void travel(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;

        travel(root->left, vec);
        vec.push_back(root->val);
        travel(root->right, vec);
    }
};
