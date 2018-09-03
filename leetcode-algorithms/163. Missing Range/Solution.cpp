// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
// Example:
//
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        map<int, int> vmap;
        vmap[lower] = upper;

        for (int i = 0; i < nums.size(); i++) {
            if (vmap.empty()) break;
            int v = nums[i];
            auto iter = vmap.lower_bound(v);// std::lower_bound(vmap.begin(), vmap.end(), v);
            if (iter == vmap.end()) iter--;

            int start;
            if (iter != vmap.end()) start = iter->first;
            if (start == v) { // start
                int end = iter->second; // end
                vmap.erase(iter);
                if (start != end) vmap[v + 1] = end;
            } else {
                int end = iter->second;
                if (v < end) {
                    vmap[start] = v - 1;
                    vmap[v + 1] = end;
                } else if (v == end) {
                    vmap[start] = end - 1;
                }
            }
        }

        vector<string> rslt;
        for (auto item : vmap) {
            string str = std::to_string(item.first);
            if (item.first != item.second) {
                str += "->";
                str += std::to_string(item.second);
            }
            rslt.push_back(str);
        }

        return rslt;
    }
};
