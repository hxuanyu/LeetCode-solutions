// Given a binary tree, find the leftmost value in the last row of the tree.
//
// Example 1:
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
// Example 2:
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        else if ((root->left == nullptr) && (root->right == nullptr)) return root->val;

        travel(root, 0);

        return vmap.begin()->second;
    }

    void travel(TreeNode* node, int level) {
        if (node == nullptr) return;
        if (!vmap.count(level)) vmap[level] = node->val;

        travel(node->left, level + 1);
        travel(node->right, level + 1);
    }

    map<int, int, greater<int>> vmap;
};

// second solution
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> que;
        que.push(root);

        int val = 0;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto top = que.front();
                if (i == 0) val = top->val;
                que.pop();

                if (top->left) que.push(top->left);
                if (top->right) que.push(top->right);
            }
        }
        return val;
    }
};
