class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        Map<Integer, Integer> vmap = new HashMap<>();
        vmap.put(0, -1);

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            if (k != 0 && vmap.containsKey(sum % k) && (i - vmap.get(sum % k) >= 2)) return true;

            if (k == 0 && vmap.containsKey(sum) && (i - vmap.get(sum) >= 2)) return true;

            if (k != 0 && !vmap.containsKey(sum % k)) {
                vmap.put(sum % k, i);
            } else if (k == 0 && !vmap.containsKey(sum)) {
                vmap.put(sum, i);
            }
        }

        return false;
    }
}
