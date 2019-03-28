class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> vmap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            vmap.put(nums[i], vmap.getOrDefault(nums[i], 0) + 1);
            if (vmap.get(nums[i]) > Math.floor(nums.length / 2)) return nums[i];
        }

        return 0;
    }
}
