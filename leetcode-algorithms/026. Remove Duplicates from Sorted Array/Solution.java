class Solution {
    public int removeDuplicates(int[] nums) {
    	if (nums.length <= 1) return nums.length;

    	int a = -1;

    	int p = 0;
    	for (; p < nums.length;) {
    		int next = p;
    		while ((next < nums.length) && (nums[p] == nums[next])) next++;

    		nums[++a] = nums[p];
    		p = next;
    	}

    	return a + 1;
    }
}
