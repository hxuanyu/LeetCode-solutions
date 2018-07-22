// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rslt;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        int local = 0;

        perm(candidates, 0, target, local, temp, rslt);
        return rslt;
    }

    void perm(vector<int>& candidates, int pos, int target, int& local, vector<int>& temp, vector<vector<int>>& rslt) {
        if (target == local) {
            rslt.push_back(temp);
            return;
        } else if ((pos >= candidates.size()) || (local > target)) return;

        for (int i = pos; i < candidates.size(); ) {
            local += candidates[i];
            temp.push_back(candidates[i]);
            perm(candidates, i + 1, target, local, temp, rslt);
            temp.pop_back();
            local -= candidates[i];

            int p = i;
            while ((p < candidates.size()) && (candidates[p] == candidates[i])) p++;
            i = p;
        }
    }
};
