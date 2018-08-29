// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:
//
// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mins(amount + 1, -1);
        mins[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int local = INT_MAX;
            for (auto c : coins) {
                if ((i - c >= 0) && (mins[i - c] >= 0)) {
                    local = min(local, mins[i - c]);
                }
            }

            mins[i] = (local == INT_MAX) ? -1 : local + 1;
        }

        return mins[amount];
    }
};
