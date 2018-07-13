// Given two arrays, write a function to compute their intersection.
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
//
// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> vmap1;
        for (auto v : nums1) vmap1[v]++;

        map<int, int> vmap2;
        for (auto v : nums2) vmap2[v]++;

        vector<int> rslt;

        set<int> se1(nums1.begin(), nums1.end());
        for (auto v : se1) {
            if (vmap1.count(v) && vmap2.count(v)) {
                int times = min(vmap1[v], vmap2[v]);
                while (times--) rslt.push_back(v);
            }
        }

        return rslt;
    }
};
