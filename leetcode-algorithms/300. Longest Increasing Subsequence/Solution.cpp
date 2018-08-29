// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Note:
//
// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        vector<int> lens(nums.size(), 0);
        lens[0] = 1;

        int maxlen = 1;
        for (int i = 1; i < lens.size(); i++) {
            int local = 0; // this is important
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                local = max(local, lens[j]);
            }
            lens[i] = local + 1;

            maxlen = max(maxlen, lens[i]);
        }

        return maxlen;
    }
};
