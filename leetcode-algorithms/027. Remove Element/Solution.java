class Solution {
    public int removeElement(int[] nums, int val) {
        int p = -1;

        for (int i = 0; i < nums.length; i++) {
        	if (nums[i] != val) {
        		int v = nums[++p];
        		nums[p] = nums[i];
        		nums[i] = v;
        	}
        }

        return p + 1;
    }
}
