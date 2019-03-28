class Solution {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer, Integer> vmap = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++) vmap.put(nums[i], i);
        String[] rslt = new String[nums.length];
        int i = 1;
        for (Map.Entry<Integer, Integer> entry : vmap.entrySet()) {
        	if (i == 1) rslt[entry.getValue()] = "Gold Medal";
        	else if (i == 2) rslt[entry.getValue()] = "Silver Medal";
        	else if (i == 3) rslt[entry.getValue()] = "Bronze Medal";
        	else rslt[entry.getValue()] = String.valueOf(i);
            i++;
        }

        return rslt;
    }
}
