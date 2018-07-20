// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rslt;
        vector<int> temp;
        perm(nums, 0, temp, rslt);
        return rslt;
    }


    void perm(vector<int>& nums, int pos, vector<int> temp, vector<vector<int>>& rslt) {
        if ((pos == nums.size()) && (temp.size() == nums.size())) {
            rslt.push_back(temp);
            return;
        }


        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            temp.push_back(nums[pos]);
            perm(nums, pos + 1, temp, rslt);
            temp.pop_back();
            swap(nums[i], nums[pos]);
        }
    }
};
