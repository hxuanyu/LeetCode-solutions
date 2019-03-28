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
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root, root);
    }

    public boolean isSymmetric(TreeNode r1, TreeNode r2) {
        if ((r1 == null) && (r2 == null)) return true;
        else if ((r1 != null) && (r2 != null)) {
            return (r1.val == r2.val) && isSymmetric(r1.left, r2.right) && isSymmetric(r1.right, r2.left);
        } return false;
    }
}
