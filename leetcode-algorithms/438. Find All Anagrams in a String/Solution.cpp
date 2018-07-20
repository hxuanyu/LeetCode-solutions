// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> rslt;
        if (s.length() < p.length()) return rslt;

        map<char, int> mapp;
        map<char, int> maps;
        for (int i = 0; i < p.length(); i++) {
            mapp[p[i]]++;
            maps[s[i]]++;
        }

        if (mapp == maps) rslt.push_back(0);

        for (int i = p.length(); i < s.length(); i++) {
            int idx = i - p.length();
            maps[s[i]]++;
            maps[s[idx]]--;
            if (maps[s[idx]] == 0) maps.erase(s[idx]);

            if (maps == mapp) {
                rslt.push_back(idx + 1);
            }
        }

        return rslt;
    }
};
