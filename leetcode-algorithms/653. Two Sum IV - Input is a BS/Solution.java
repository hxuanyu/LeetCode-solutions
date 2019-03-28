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
    public boolean findTarget(TreeNode root, int k) {
        visit(root);

        int a = 0;
        int b = vlist.size() - 1;
        while (a < b) {
        	int sum = vlist.get(a) + vlist.get(b);
        	if (sum == k) return true;
        	else if (sum > k) b--;
        	else a++;
        }

        return false;
    }

    private void visit(TreeNode node) {
    	if (node == null) return;

    	visit(node.left);
    	vlist.add(node.val);
    	visit(node.right);
    }

    List<Integer> vlist = new ArrayList<>();
}
