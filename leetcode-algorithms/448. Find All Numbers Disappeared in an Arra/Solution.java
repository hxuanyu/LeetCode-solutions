class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
        	while ((nums[i] != i + 1) && (nums[nums[i] - 1] != nums[i])) {
        		int v = nums[i];
        		nums[i] = nums[nums[i] - 1];
        		nums[v - 1] = v;
        	}
        }

        List<Integer> ar = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
        	if (nums[i] != i + 1) ar.add(i+1);
        }

        return ar;
    }
}
