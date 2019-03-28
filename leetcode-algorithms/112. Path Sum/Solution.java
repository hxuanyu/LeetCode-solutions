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
    public boolean hasPathSum(TreeNode root, int sum) {
        List<TreeNode> temp = new ArrayList<>();
        List<List<TreeNode>> solutions = new ArrayList<>();

        visit(root, temp, solutions, sum);
        return !solutions.isEmpty();
    }

    void visit(TreeNode root, List<TreeNode> currentPath, List<List<TreeNode>> solutions, int target) {
        if (root == null) return;
        else if ((root.left == null) && (root.right == null) && (root.val == target)) {
            currentPath.add(root);
            solutions.add(currentPath);
            currentPath.remove(currentPath.size() - 1);
            return;
        }

        currentPath.add(root);
        visit(root.left, currentPath, solutions, target - root.val);
        visit(root.right, currentPath, solutions, target - root.val);
        return;
    }
}
