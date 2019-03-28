class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) return 0;

        int minv = prices[0];

        int maxpro = 0;
        for (int i = 1; i < prices.length; i++) {
            maxpro = Math.max(maxpro, prices[i] - minv);
            minv = Math.min(minv, prices[i]);
        }

        return maxpro;
    }
}
