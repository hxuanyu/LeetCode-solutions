class Solution {
    public int climbStairs(int n) {
    	int[] steps = new int[n + 1];
    	steps[0] = 1;

    	for (int i = 1; i <= n; i++) {
    		if (i - 1 >= 0) steps[i] += steps[i - 1];
    		if (i - 2 >= 0) steps[i] +=  steps[i - 2];
    	}

    	return steps[n];
    }
}
