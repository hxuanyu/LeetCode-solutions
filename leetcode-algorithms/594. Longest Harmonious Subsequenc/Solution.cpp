// We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
//
// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
//
// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
// Note: The length of the input array will not exceed 20,000.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        set<int> se;
        map<int, int> countmap;

        for (auto v : nums) {
            countmap[v]++;
            se.insert(v);
        }

        int maxlen = 0;
        for (auto v : se) {
            if (countmap.count(v + 1)) maxlen = max(maxlen, countmap[v] + countmap[v + 1]);
            if (countmap.count(v - 1)) maxlen = max(maxlen, countmap[v] + countmap[v - 1]);
        }

        return maxlen;

    }
};
