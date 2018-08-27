// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.
//
// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.
//
// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
//
// The right-most node is also defined by the same way with left and right exchanged.
//
// Example 1
// Input:
//   1
//    \
//     2
//    / \
//   3   4
//
// Ouput:
// [1, 3, 4, 2]
//
// Explanation:
// The root doesn't have left subtree, so the root itself is left boundary.
// The leaves are node 3 and 4.
// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
// So order them in anti-clockwise without duplicates and we have [1,3,4,2].
// Example 2
// Input:
//     ____1_____
//    /          \
//   2            3
//  / \          /
// 4   5        6
//    / \      / \
//   7   8    9  10
//
// Ouput:
// [1,2,4,7,8,9,10,6,3]
//
// Explanation:
// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
// The leaves are node 4,7,8,9,10.
// The right boundary are node 1,3,6,10. (10 is the right-most node).
// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> rslt;
        if (root == nullptr) return rslt;
        else if ((root->left == nullptr) && (root->right == nullptr)) {
            rslt.push_back(root->val);
            return rslt;
        }
        vector<int> lb = leftbou(root);
        vector<int> rb = rightbou(root);
        reverse(rb.begin(), rb.end());
        vector<int> leafes;
        getleafes(root, leafes);

        rslt.insert(rslt.end(), lb.begin(), lb.end());
        rslt.insert(rslt.end(), leafes.begin(), leafes.end());
        rslt.insert(rslt.end(), rb.begin(), rb.end());
        return rslt;
    }

    vector<int> leftbou(TreeNode* root) {
        vector<int> rslt;
        rslt.push_back(root->val);
        if (root->left) travel(root->left, rslt, true);
        return rslt;
    }

    vector<int> rightbou(TreeNode* root) {
        vector<int> rslt;
        if (root->right) travel(root->right, rslt, false);
        return rslt;
    }

    void travel(TreeNode* node, vector<int>& rslt, bool bleft) {
        if (node == nullptr) return;
        if ((node->left == nullptr) && (node->right == nullptr)) return;
        rslt.push_back(node->val);
        if (bleft) {
            if (node->left) travel(node->left, rslt, bleft);
            else travel(node->right, rslt, bleft);
        } else {
            if (node->right) travel(node->right, rslt, bleft);
            else travel(node->left, rslt, bleft);
        }
    }

    void getleafes(TreeNode* node, vector<int>& leafes) {
        if (node == nullptr) return;
        if ((node->left == nullptr) && (node->right == nullptr)) leafes.push_back(node->val);

        getleafes(node->left, leafes);
        getleafes(node->right, leafes);
    }
};
