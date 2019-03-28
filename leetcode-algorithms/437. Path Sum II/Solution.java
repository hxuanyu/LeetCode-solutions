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
    public int pathSum(TreeNode root, int sum) {
        visit(root, sum);
        return gcount;
    }

    void visit(TreeNode node, int sum) {
    	if (node == null) return;

    	gcount += getCount(node, sum);

    	visit(node.left, sum);
    	visit(node.right, sum);
    }

    int getCount(TreeNode node, int sum) {
    	int count = 0;
    	if (node == null) return count;
    	else if (node.val == sum) count += 1;

    	count += getCount(node.left, sum - node.val);
    	count += getCount(node.right, sum - node.val);
    	return count;
    }
    int gcount = 0;
}
