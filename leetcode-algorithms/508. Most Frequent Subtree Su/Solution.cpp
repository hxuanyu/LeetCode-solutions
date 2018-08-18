// Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
//
// Examples 1
// Input:
//
//   5
//  /  \
// 2   -3
// return [2, -3, 4], since all the values happen only once, return all of them in any order.
// Examples 2
// Input:
//
//   5
//  /  \
// 2   -5
// return [2], since 2 happens twice, however -5 only occur once.
// Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
     vector<int> findFrequentTreeSum(TreeNode* root) {
         getheight(root);
         return valset;
     }

     int getheight(TreeNode* root) {
         if (root == nullptr) return 0;

         int val = root->val;
         int left = getheight(root->left);
         int right = getheight(root->right);
         val += (left + right);
         count[val]++;
         if (count[val] == maxc) { valset.push_back(val); }
         else if (count[val] > maxc) {
             maxc = count[val];
             valset.clear();
             valset.push_back(val);
         }
         return val;
     }

     vector<int> valset;
     map<int, int> count;
     int maxc = 0;
 };
