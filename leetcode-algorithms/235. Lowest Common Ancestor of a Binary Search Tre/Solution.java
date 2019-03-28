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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (p.val > q.val) return impl(root, q, p);
        else return impl(root, p, q);
    }

    public TreeNode impl(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if ((root == p) || (root == q)) return root;

        if (q.val < root.val) return impl(root.left, p, q);
        else if (p.val > root.val) return impl(root.right, p, q);
        else return root;
    }
}
