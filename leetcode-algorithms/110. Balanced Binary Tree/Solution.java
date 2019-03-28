/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        balanced = true;
        getHeight(root);
        return balanced;
    }

    int getHeight(TreeNode root) {
        if (root == null) return 0;

        int left = getHeight(root.left);
        int right = getHeight(root.right);
        if (Math.abs(left - right) >= 2) balanced = false;
        return 1 + Math.max(left, right);
    }

    boolean balanced;
}
