class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> sets = new HashSet<Integer>();
        for (int v : candies) sets.add(v);

        int total = candies.length;
        int kinds = sets.size();
        if (kinds * 2 >= total) return total / 2;
        else return kinds;
    }
}
