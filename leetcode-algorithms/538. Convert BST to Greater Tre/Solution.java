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
    public TreeNode convertBST(TreeNode root) {
    	visit(root);
    	return root;
    }

    private void visit(TreeNode node) {
    	if (node == null) return;
    	visit(node.right);
    	node.val += sum;
    	sum = node.val;
    	visit(node.left);
    }

    int sum = 0;
}
