// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
// Note:
//
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:
//
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        vector<vector<int>> rslt;

        perm(nums, 0, k, n, temp, rslt);
        return rslt;
    }

    void perm(vector<int>& nums, int pos, int k, int target, vector<int>& temp, vector<vector<int>>& rslt) {
         if (temp.size() == k) {
             int total = 0;
             for (auto v : temp) total += v;
             if (total == target) {
                 rslt.push_back(temp);
             }
             return;
         }

         if (pos >= nums.size()) return;

         for (int i = pos; i < nums.size(); i++) {
             temp.push_back(nums[i]);
             perm(nums, i + 1, k, target, temp, rslt);
             temp.pop_back();
         }
    }
};
