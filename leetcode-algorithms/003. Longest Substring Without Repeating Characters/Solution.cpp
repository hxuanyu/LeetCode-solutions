// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", which the length is 3.
// Example 2:
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> vset;
        int start = 0;
        int maxlen = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            if (vset.count(s[i]) == 0) vset.insert(s[i]);
            else {
                int len = i - start;
                maxlen = max(maxlen, len);

                while (vset.count(s[i])) {
                    vset.erase(s[start++]);
                }
                vset.insert(s[i]);
            }
        }

        return max(maxlen, int(vset.size()));
    }
};
