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
    public int minDepth(TreeNode root) {
        return mind(root);
    }

    private int mind(TreeNode node) {
        if (node == null) return 0;
        else if ((node.left == null) && (node.right == null)) return 1;
        else if ((node.left != null) && (node.right != null)) return 1 + Math.min(mind(node.left), mind(node.right));
        else if (node.left != null) return 1 + mind(node.left);
        else return 1 + mind(node.right);
    }
}
