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
     class countandtotal {
         public countandtotal(int c, double t) { count = c; total = t;}
         public int count;
         public double total;
     }

     public List<Double> averageOfLevels(TreeNode root) {

         TreeMap<Integer, countandtotal> map = new TreeMap<Integer, countandtotal>();
         travel(root, 0, map);

         ArrayList<Double> rslt = new ArrayList<Double>();

         for (Map.Entry me : map.entrySet()) {
             double total = ((countandtotal)me.getValue()).total;
             int count = ((countandtotal)me.getValue()).count;
             rslt.add(total/count);
         }

         return rslt;

     }

     void travel(TreeNode node, int level, TreeMap<Integer, countandtotal> map) {
         if (node == null) return;

         if (!map.containsKey(level)) {
             map.put(level, new countandtotal(1, (double) node.val));
         } else {
             countandtotal val = map.get(level);
             val.count++;
             val.total += (double)node.val;
             map.put(level, val);
         }

         travel(node.left, level + 1, map);
         travel(node.right, level + 1, map);
     }
 }
