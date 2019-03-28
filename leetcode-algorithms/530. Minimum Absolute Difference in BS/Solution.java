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
    public int getMinimumDifference(TreeNode root) {
        visit(root);

        int mindiff = Integer.MAX_VALUE;
        for (int i = 0; i < rslt.size(); i++) {
        	if (i >= 1) mindiff = Math.min(mindiff, rslt.get(i) - rslt.get(i - 1));
        	if (i < rslt.size() - 1) mindiff = Math.min(mindiff, rslt.get(i + 1) - rslt.get(i));
        }

        return mindiff;
    }

    private void visit(TreeNode node) {
    	if (node == null) return;

    	visit(node.left);
    	rslt.add(node.val);
    	visit(node.right);
    }

    List<Integer> rslt = new ArrayList<>();
}
