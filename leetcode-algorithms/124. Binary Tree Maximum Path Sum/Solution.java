class Solution {
    public int maxPathSum(TreeNode root) {
        visit(root);

        return maxv;
    }

    void visit(TreeNode node) {
        if (node == null) return;

        int local = node.val + Math.max(0, getmaxpath(node.left)) + Math.max(0, getmaxpath(node.right));
        maxv = Math.max(local, maxv);

        visit(node.left);
        visit(node.right);
    }

    int getmaxpath(TreeNode node) {
        if (node == null) return 0;
        else if (node.left == null && node.right == null) return node.val;

        if (maxpath.containsKey(node)) return maxpath.get(node);

        int val = node.val + Math.max(0, Math.max(getmaxpath(node.left), getmaxpath(node.right)));
        maxpath.put(node, val);
        return val;
    }

    Map<TreeNode, Integer> maxpath = new HashMap<>();
    int maxv = Integer.MIN_VALUE;
}
