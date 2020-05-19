class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> countmap = new HashMap<>();
        countmap.put(0, 1);

        int sum = 0;
        int total = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (countmap.containsKey(sum - k)) {
                total += countmap.get(sum - k);
            }
            countmap.put(sum, countmap.getOrDefault(sum, 0) + 1);
        }

        return total;
    }
}
