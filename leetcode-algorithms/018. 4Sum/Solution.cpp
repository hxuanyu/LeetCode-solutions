// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rslt;
        if (nums.size() < 4) return rslt;

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size() - 4;) {
            for (int j = i + 1; j <= nums.size() - 3;) {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum == target) {
                        rslt.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int p = right;
                        while ((p >= left) && (nums[p] == nums[right])) p--;
                        right = p;

                        p = left;
                        while ((p <= right) && (nums[p] == nums[left])) p++;
                        left = p;
                    } else if (sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
                int p = j;
                while ((p <= nums.size() - 3) && (nums[p] == nums[j])) p++;
                j = p;
            }
            int p = i;
            while ((p <= nums.size() - 4) && (nums[p] == nums[i])) p++;
            i = p;
        }
        return rslt;
    }
};
