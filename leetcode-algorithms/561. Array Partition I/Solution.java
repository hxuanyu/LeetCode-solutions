class Solution {
    public int arrayPairSum(int[] nums) {
    	List<Integer> ar = new ArrayList<>();
    	for (int i = 0; i < nums.length; i++) ar.add(nums[i]);

        Collections.sort(ar);

        int total = 0;
        for (int i = 0; i < nums.length; i += 2) {
        	total += ar.get(i);
        }

        return total;
    }
}
