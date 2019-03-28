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
    public int findTilt(TreeNode root) {
    	visit(root);
    	return total;
    }

    private void visit(TreeNode root) {
    	if (root == null) return;

    	total += Math.abs(calcsum(root.left) - calcsum(root.right));

    	visit(root.left);
    	visit(root.right);
    }

    private int calcsum(TreeNode root) {
    	if (root == null) return 0;

    	return root.val + calcsum(root.left) + calcsum(root.right);
    }

    int total = 0;
}
