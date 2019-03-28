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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<TreeNode> temp = new ArrayList<>();
        List<List<TreeNode>> solutions = new ArrayList<>();
        visit(root, temp, solutions, sum);

        List<List<Integer>> rslt = new ArrayList<>();

        for (List<TreeNode> list : solutions) {
            List<Integer> t = new ArrayList<>();
            for (TreeNode node : list) {
                t.add(node.val);
            }
            rslt.add(t);
        }

        return rslt;
    }

    void visit(TreeNode root, List<TreeNode> currentPath, List<List<TreeNode>> solutions, int target) {
        if (root == null) return;
        else if ((root.left == null) && (root.right == null) && (root.val == target)) {
            currentPath.add(root);
            solutions.add(new ArrayList<TreeNode>(currentPath));
            currentPath.remove(currentPath.size() - 1);
            return;
        }

        currentPath.add(root);
        visit(root.left, currentPath, solutions, target - root.val);
        visit(root.right, currentPath, solutions, target - root.val);
        currentPath.remove(currentPath.size() - 1);
        return;
    }
}
