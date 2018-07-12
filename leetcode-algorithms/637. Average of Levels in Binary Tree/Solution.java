// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.
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
    public List<Double> averageOfLevels(TreeNode root) {

        TreeMap<Integer, Double> map_level_total = new TreeMap<Integer, Double>();
        TreeMap<Integer, Integer> map_level_count = new TreeMap<Integer, Integer>();
        travel(root, 0, map_level_total, map_level_count);

        ArrayList<Double> rslt = new ArrayList<Double>();

        for (Map.Entry me : map_level_total.entrySet()) {
            double total = (Double)me.getValue();
            int level = (Integer)me.getKey();

            int count = map_level_count.get(me.getKey());
            rslt.add((double)total/count);
        }

        return rslt;

    }

    void travel(TreeNode node, int level, TreeMap<Integer, Double> map_level_total, TreeMap<Integer, Integer> map_level_count) {
        if (node == null) return;

        if (!map_level_total.containsKey(level)) map_level_total.put(level, (double)node.val);
        else map_level_total.put(level, map_level_total.get(level) + (double)node.val);

        if (!map_level_count.containsKey(level)) map_level_count.put(level, 1);
        else map_level_count.put(level, map_level_count.get(level) + 1);


        travel(node.left, level + 1, map_level_total, map_level_count);
        travel(node.right, level + 1, map_level_total, map_level_count);
    }
}
