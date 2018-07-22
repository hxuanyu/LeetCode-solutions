// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rslt;
        vector<int> temp;
        int local = 0;
        perm(candidates, 0, target, local, temp, rslt);
        return rslt;
    }

    void perm(vector<int>& candidates, int pos, int target, int& local, vector<int>& temp, vector<vector<int>>& rslt) {
        if (target == local) {
            rslt.push_back(temp);
            return;
        } else if ((pos >= candidates.size()) || (local > target)) return;

        for (int i = pos; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            local += candidates[i];
            perm(candidates, i, target, local, temp, rslt);
            temp.pop_back();
            local -= candidates[i];
        }
    }
};
