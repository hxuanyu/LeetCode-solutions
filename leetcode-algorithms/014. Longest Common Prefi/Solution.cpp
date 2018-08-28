// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:
//
// All given inputs are in lowercase letters a-z.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        else if (strs.size() == 1) return strs[0];

        int commlen = INT_MAX;

        for (auto str : strs) commlen = min(commlen, int(str.size()));

        set<string> se;
        for (int i = 0; i < commlen; i++) {
            se.clear();
            for (auto str : strs) {
                string sub = str.substr(0, i + 1);
                if (se.empty()) se.insert(sub);
                else if (se.count(sub) == 0) return str.substr(0, i);
            }
        }

        return strs[0].substr(0, commlen);
    }
};
