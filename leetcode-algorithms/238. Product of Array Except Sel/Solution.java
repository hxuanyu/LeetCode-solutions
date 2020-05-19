class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] rslt = new int[nums.length];
        rslt[0] = 1;
        int left = 1;

        for (int i = 1; i < nums.length; i++) {
            rslt[i] = nums[i - 1] * left;
            left *= nums[i - 1];
        }

        int right = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            rslt[i] = rslt[i] * right;
            right *= nums[i];
        }

        return rslt;
    }
}
