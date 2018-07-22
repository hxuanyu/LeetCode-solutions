// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rslt;
        vector<int> temp;

        perm(1, n, k, temp, rslt);
        return rslt;
    }

    void perm(int pos, int n, int k, vector<int>& temp, vector<vector<int>>& rslt) {
        if (temp.size() == k) {
            rslt.push_back(temp);
            return;
        }

        for (int i = pos; i <= n; i++) {
            temp.push_back(i);
            perm(i + 1, n, k, temp, rslt);
            temp.pop_back();
        }
    }
};
