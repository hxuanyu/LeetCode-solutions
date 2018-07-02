class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null) return 0;
        if (target < nums[0]) return 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) return i;
            else if (target < nums[i]) return i;
        }

        return nums.length;
    }
}
