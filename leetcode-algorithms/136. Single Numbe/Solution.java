class Solution {
    public int singleNumber(int[] nums) {
        int rslt = 0;

        for (int i = 0; i < nums.length; i++) rslt ^= nums[i];

        return rslt;
    }
}
