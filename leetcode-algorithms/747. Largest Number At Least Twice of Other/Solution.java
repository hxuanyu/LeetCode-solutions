class Solution {
    public int dominantIndex(int[] nums) {
        TreeSet<Integer> vset = new TreeSet<>();
        HashMap<Integer, Integer> vmap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            vset.add(nums[i]);
            vmap.put(nums[i], i);
        }

        int largest = 0;
        int second = 0;
        Iterator<Integer> iter = vset.descendingIterator();
        if (iter.hasNext()) largest = iter.next();
        if (iter.hasNext()) second = iter.next();

        if (largest >= 2 * second) return vmap.get(largest);
        return -1;
    }
}
