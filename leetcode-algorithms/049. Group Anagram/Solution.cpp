// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
//
// All inputs will be in lowercase.
// The order of your output does not matter.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> vmap;

        for (auto str : strs) {
            auto oldstr = str;
            sort(str.begin(), str.end());
            vmap[str].push_back(oldstr);
        }

        vector<vector<string>> rslt;
        for (auto item : vmap) {
            rslt.push_back(item.second);
        }

        return rslt;
    }
};
