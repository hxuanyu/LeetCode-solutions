// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rslt;
        if (nums.size() < 3) return rslt;

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size() - 3;) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    rslt.push_back({nums[i], nums[start], nums[end]});
                    int p = start;
                    while ((p <= end) && (nums[p] == nums[start])) p++;
                    start = p;

                    p = end;
                    while ((p >= start) && (nums[p] == nums[end])) p--;
                    end = p;
                } else if (sum > 0) {
                    int p = end;
                    while ((p >= start) && (nums[p] == nums[end])) p--;
                    end = p;
                } else {
                    int p = start;
                    while ((p <= end) && (nums[p] == nums[start])) p++;
                    start = p;
                }
            }

            int p = i;
            while ((p <= nums.size() - 3) && (nums[p] == nums[i])) p++;
            i = p;
        }

        return rslt;
    }
};
