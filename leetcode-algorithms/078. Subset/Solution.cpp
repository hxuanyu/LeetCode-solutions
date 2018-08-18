// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rslt;
        rslt.push_back(vector<int>());

        if (nums.empty()) return rslt;

        vector<int> temp;
        travel(nums, 0, temp, rslt);
        return rslt;
    }

    void travel(vector<int>& nums, int pos, vector<int>& temp, vector<vector<int>>& rslt) {
        if (pos == nums.size()) return;

        for (int i = pos; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            rslt.push_back(temp);
            travel(nums, i + 1, temp, rslt);
            temp.pop_back();
        }
    }
};
