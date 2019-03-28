class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int i = 0;
        int maxlen = 0;
        while (i < nums.length) {
        	int p = i;

        	while ((i < nums.length) && (nums[i] != 1)) i++;
        	if (i == nums.length) break;
        	p = i;

        	while ((p < nums.length) && (nums[p] == 1)) p++;
        	maxlen = Math.max(p - i, maxlen);
        	i = p;
        }

        return maxlen;
    }
}
