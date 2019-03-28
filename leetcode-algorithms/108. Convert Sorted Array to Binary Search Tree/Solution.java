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
    public TreeNode sortedArrayToBST(int[] nums) {
        return impl(nums, 0, nums.length - 1);
    }

    private TreeNode impl(int[] nums, int first, int last) {
        if (first > last) return null;

        int mid = first + (last - first) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = impl(nums, first, mid - 1);
        root.right = impl(nums, mid + 1, last);
        return root;
    }
}
