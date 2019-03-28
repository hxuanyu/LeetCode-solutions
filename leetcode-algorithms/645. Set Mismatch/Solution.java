class Solution {
    public int[] findErrorNums(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
        	while ((nums[i] != i + 1) && (nums[nums[i] - 1] != nums[i])) {
        		int old = nums[i];
        		nums[i] = nums[old - 1];
        		nums[old - 1] = old;
        	}
        }

        for (int i = 0; i < nums.length; i++) {
        	if (nums[i] != i + 1) return new int[] {nums[i], i + 1};
        }

        return null;
    }
}
