// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
//
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        map<char, int> tmap;
        for (auto v : t) tmap[v]++;

        int count = 0;
        int start = 0;
        int minlen = INT_MAX;
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (tmap.count(s[i])) {
                //count++;
                tmap[s[i]]--;
                if (tmap[s[i]] >= 0) count++;
            }

            while (count == t.size()) {
                int len = i - start + 1;
                if (len < minlen) {
                    minlen = len;
                    pos = start;
                }
                if (tmap.count(s[start])) {
                    tmap[s[start]]++;
                    if (tmap[s[start]] > 0) count--;
                }
                start++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(pos, minlen);
    }
};
