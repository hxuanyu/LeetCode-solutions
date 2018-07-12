// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        TreeMap<Integer, List<Integer>> vmap = new TreeMap<Integer, List<Integer>>(Collections.reverseOrder());

        travel(root, 0, vmap);

        List<List<Integer>> rslt = new ArrayList<List<Integer>>();

        for (Map.Entry me : vmap.entrySet()) {
            rslt.add((ArrayList<Integer>)me.getValue());
        }
        return rslt;

    }

    void travel(TreeNode node, int level, TreeMap<Integer, List<Integer>> vmap) {
        if (node == null) return;

        if (!vmap.containsKey(level)) {
            ArrayList<Integer> list = new ArrayList<Integer>();
            list.add(node.val);
            vmap.put(level, list);
        } else {
            vmap.get(level).add(node.val);
        }

        travel(node.left, level + 1, vmap);
        travel(node.right, level + 1, vmap);
    }
}
