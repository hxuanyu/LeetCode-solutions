class Solution {
    public void moveZeroes(int[] nums) {
        int p = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) continue;

            ++p;
            int temp = nums[p];
            nums[p] = nums[i];
            nums[i] = temp;
        }
    }
}
