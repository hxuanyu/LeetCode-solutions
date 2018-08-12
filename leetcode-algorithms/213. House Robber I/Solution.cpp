//
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        p[make_pair(0, 0)] = nums[0];
        if (nums.size() == 1) return nums[0];

        return max(impl(nums, 0, nums.size() - 2), impl(nums, 1, nums.size() - 1));
    }

    int impl(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        else if (start + 1 == end) return max(nums[start], nums[end]);

        if (p.count(make_pair(start, end))) return p[make_pair(start, end)];

        int v = max(impl(nums, start, end - 2) + nums[end], impl(nums, start, end - 1));
        p[make_pair(start, end)] = v;
        return v;
    }

    map<pair<int, int>, int> p;
};
