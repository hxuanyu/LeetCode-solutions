// Given a binary array, find the maximum number of consecutive 1s in this array.
//
// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:
//
// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int maxlen = 0;

        while (a < nums.size()) {
            while ((a < nums.size() && nums[a] != 1)) a++;
            b = a;
            while ((b < nums.size()) && (nums[b] == 1)) b++;
            maxlen = max(maxlen, b - a);
            a = b;
        }

        return maxlen;
    }
};
