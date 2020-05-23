class Solution {
    public int search(int[] nums, int target) {
        return impl(nums, 0, nums.length - 1, target);
    }

    private int impl(int[] nums, int left, int right, int val) {
        if (left > right) return -1;
        if (left == right) return nums[left] == val ? left : -1;

        int mid = left + (right - left) / 2;
        if (nums[mid] == val) return mid;

        if (nums[mid] > nums[left]) {
            if (nums[left] <= val && val < nums[mid]) return impl(nums, left, mid - 1, val);
            else return impl(nums, mid + 1, right, val);
        } else if (nums[mid] < nums[left]) {
            if (nums[mid] < val & val <= nums[right]) return impl(nums, mid + 1, right, val);
            else return impl(nums, left, mid - 1, val);
        } else if (nums[left] == nums[mid]) {
            return impl(nums, left + 1, right, val);
        }

        return -1;
    }
}
