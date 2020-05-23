class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        visit(0, root);

        List<Integer> rslt = new ArrayList<>();
        for (TreeNode node : levelnode.values()) {
            rslt.add(node.val);
        }

        return rslt;
    }

    private void visit(int level, TreeNode node) {
        if (node == null) return;

        if (!levelnode.containsKey(level)) {
            levelnode.put(level, node);
        }

        visit(level + 1, node.right);
        visit(level + 1, node.left);
    }

    TreeMap<Integer, TreeNode> levelnode = new TreeMap<>();
}
