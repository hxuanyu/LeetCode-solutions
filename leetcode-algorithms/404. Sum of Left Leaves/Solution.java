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
    public int sumOfLeftLeaves(TreeNode root) {
        visit(root, false);
        return count;
    }

    void visit(TreeNode root, boolean lefttree) {
    	if (root == null) return;

    	if ((root.left == null) && (root.right == null)) {
    		if (lefttree) count += root.val;
    	} else {
    		visit(root.left, true);
    		visit(root.right, false);
    	}
    }

    int count = 0;
}
