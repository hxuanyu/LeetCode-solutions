class Solution {
    public int maxSubArray(int[] nums) {
    	if (nums.length == 0) return 0;

    	int maxv = nums[0];
    	int sum = nums[0];
    	for (int i = 1; i < nums.length; i++) {
    		if (sum < 0) sum = 0;

    		sum += nums[i];
    		maxv = Math.max(maxv, sum);
    	}

    	return maxv;
    }
}
