// Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
//
// Example 1:
// Input: [1,3,5,4,7]
// Output: 3
// Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
// Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
// Example 2:
// Input: [2,2,2,2,2]
// Output: 1
// Explanation: The longest continuous increasing subsequence is [2], its length is 1.
// Note: Length of the array will not exceed 10,000.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 0;

        int a = 0;

        while (a < nums.size()) {
            int p = a;
            int locallen = 1;
            while ((p + 1< nums.size()) && (nums[p + 1] > nums[p])) {
                p = p + 1;
                locallen++;
            }

            maxlen = max(maxlen, locallen);

            int dec = p + 1;
            while ((dec + 1< nums.size()) && (nums[dec + 1] <= nums[dec])) dec++;
            a = dec;
        }

        return maxlen;
    }
};
