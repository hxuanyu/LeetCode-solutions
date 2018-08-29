// You need to find the largest value in each row of a binary tree.
//
// Example:
// Input:
//
//           1
//          / \
//         3   2
//        / \   \
//       5   3   9
//
// Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rslt;
        if (root == nullptr) return rslt;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            int rowmax = INT_MIN;

            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();

                rowmax = max(rowmax, top->val);
                if (top->left) que.push(top->left);
                if (top->right) que.push(top->right);
            }

            rslt.push_back(rowmax);
        }

        return rslt;
    }
};
