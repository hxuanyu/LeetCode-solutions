// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindis = INT_MAX;
        int val = 0;
        for (int i = 0; i <= nums.size() - 3; i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum == target) return sum;
                else {
                    int dis = abs(sum - target);
                    if (dis < mindis) {
                        mindis = dis;
                        val = sum;
                    }
                    if (sum > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }

        return val;
    }
};
