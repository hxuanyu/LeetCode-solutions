//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> rslt;
        vector<int> temp;

        map<int, int> vmap;
        for (auto v : nums) vmap[v]++;
        perm(vmap, nums.size(), temp, rslt);
        return rslt;
    }

    void perm(map<int, int>& vmap, int size,  vector<int>& temp, vector<vector<int>>& rslt) {
        if (temp.size() == size) {
            rslt.push_back(temp);
            return;
        }

        for (auto& v : vmap) {
            if (v.second > 0) {
                v.second--;
                temp.push_back(v.first);
                perm(vmap, size, temp, rslt);
                temp.pop_back();
                v.second++;
            }
        }
    }
};
