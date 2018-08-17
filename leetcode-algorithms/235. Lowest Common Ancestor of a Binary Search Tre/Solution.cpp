// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
// Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
//
//         _______6______
//        /              \
//     ___2__          ___8__
//    /      \        /      \
//    0      _4       7       9
//          /  \
//          3   5
// Example 1:
//
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:
//
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
//              according to the LCA definition.
// Note:
//
// All of the nodes' values will be unique.
// p and q are different and both values will exist in the BST.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         TreeNode* s = p->val < q->val ? p : q;
         TreeNode* l = p->val < q->val ? q : p;
         return impl(root, s, l);
     }

     TreeNode* impl(TreeNode* root, TreeNode* s, TreeNode* l) {
         if ((root == s) || (root == l)) return root;
         if ((s->val < root->val) && (root->val < l->val)) return root;
         else if (root->val > l->val) return impl(root->left, s, l);
         else if (s->val > root->val) return impl(root->right, s, l);
     }
 };
