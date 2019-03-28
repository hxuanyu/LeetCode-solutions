class Solution {
    public int missingNumber(int[] nums) {
        int v = 0;
        int n = nums.length;
        for (int i = 0; i <= n; i++) v = v ^ i;
        for (int i = 0; i < nums.length; i++) v = v ^ nums[i];

        return v;
    }
}
