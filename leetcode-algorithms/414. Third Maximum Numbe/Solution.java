class Solution {
    public int thirdMax(int[] nums) {
        long max1 = Long.MIN_VALUE;
        long max2 = Long.MIN_VALUE;
        long max3 = Long.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
        	long v = nums[i];

        	if (v > max1) {
        		max3 = max2;
        		max2 = max1;
        		max1 = v;
        	} else if ((v > max2) && (v < max1)) {
        		max3 = max2;
        		max2 = v;
        	} else if ((v > max3) && (v < max2)) {
        		max3 = v;
        	}
        }

        return max3 == Long.MIN_VALUE ? (int)max1 : (int)max3;
    }

}
