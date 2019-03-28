class Solution {
    public int findLHS(int[] nums) {
    	Set<Integer> vset = new HashSet<>();
    	for (int v : nums) vset.add(v);

    	int maxl = 0;
        for (int i = 0; i < nums.length; i++) {
        	maxl = Math.max(maxl, find(nums, i, vset));
        }

        return maxl;
    }

    private int find(int[] nums, int idx, Set<Integer> vset) {
    	int v = nums[idx];
    	int up = 0;
    	if (vset.contains(v + 1)) {
    		for (int i = 0; i < nums.length; i++) {
    			if ((nums[i] == v) || (nums[i] == v + 1)) up++;
    		}
    	}

    	int down = 0;
    	if (vset.contains(v - 1)) {
    		for (int i = 0; i < nums.length; i++) {
    			if ((nums[i] == v) || (nums[i] == v - 1)) down++;
    		}
    	}

    	return Math.max(down, up);
    }
}
