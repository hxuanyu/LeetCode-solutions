class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> vmap = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (vmap.containsKey(target - nums[i])) return new int[]{vmap.get(target - nums[i]), i};
            vmap.put(nums[i], i);
        }

        return new int[0];
    }
}
