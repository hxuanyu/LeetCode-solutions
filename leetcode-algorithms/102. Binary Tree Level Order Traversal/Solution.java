// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        TreeMap<Integer, List<Integer>> vmap = new TreeMap<Integer, List<Integer>>();

        travel(root, 0, vmap);

        List<List<Integer>> rslt = new ArrayList<List<Integer>>();

        for (Map.Entry me : vmap.entrySet()) {
            rslt.add((List<Integer>)me.getValue());
        }

        return rslt;
    }

    public void travel(TreeNode node, int level, TreeMap<Integer, List<Integer>> vmap) {
        if (node == null) return;

        if (vmap.containsKey(level)) ((List<Integer>)vmap.get(level)).add(node.val);
        else {
            ArrayList<Integer> ar = new ArrayList<Integer>(Arrays.asList(node.val));
            vmap.put(level, ar);
        }
        travel(node.left, level + 1, vmap);
        travel(node.right, level + 1, vmap);
    }
}
