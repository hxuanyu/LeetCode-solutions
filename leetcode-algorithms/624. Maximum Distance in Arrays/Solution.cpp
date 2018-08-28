// Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.
//
// Example 1:
// Input:
// [[1,2,3],
//  [4,5],
//  [1,2,3]]
// Output: 4
// Explanation:
// One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
// Note:
// Each given array will have at least 1 number. There will be at least two non-empty arrays.
// The total number of the integers in all the m arrays will be in the range of [2, 10000].
// The integers in the m arrays will be in the range of [-10000, 10000].
struct data {
    data(int val_, int idx_) { val = val_; idx = idx_; }
    int val;
    int idx;
};

class cmp {
public:
    bool operator()(const data& a, const data& b) { return a.val < b.val; }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<data, cmp> ssmall;
        multiset<data, cmp> slarge;

        for (int i = 0; i < arrays.size(); i++) {
            ssmall.insert(data(arrays[i][0], i));
            slarge.insert(data(arrays[i].back(), i));
        }

        auto iter = ssmall.begin();
        data smallest = *iter;
        data small2 = *(++iter);

        auto iiter = slarge.rbegin();
        data largest = *iiter;
        data larg2 = *(++iiter);

        if (smallest.idx != largest.idx) return largest.val - smallest.val;
        else return max(largest.val - small2.val, larg2.val - smallest.val);

    }
};
