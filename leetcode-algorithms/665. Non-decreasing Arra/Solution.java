class Solution {
    public boolean checkPossibility(int[] nums) {
    	int pos = -1;
    	int count = 0;
        for (int i = 0; i < nums.length - 1; i++) {
        	if (nums[i + 1] < nums[i]) {
        		count++;
        		if (count == 2) return false;
            	pos = i;
        	}
        }

        if (pos == -1) return true;
        if ((pos == 0) || (pos == nums.length - 2)) return true;
        return (nums[pos + 2] >= nums[pos]) || (nums[pos + 1] >= nums[pos - 1]);
    }
}
