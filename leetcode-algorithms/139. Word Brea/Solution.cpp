// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;

        set<string> dic(wordDict.begin(), wordDict.end());
        return find(s, 0, dic);
    }

    bool find(string& s, int pos, set<string>& dic) {
        if (pos == s.length()) return true;


        for (int end = pos; end < s.size(); end++) {
            string sub = s.substr(pos, end - pos + 1);
            if (dic.count(sub) && (findmap.count(end + 1) == 0) && find(s, end + 1, dic)) return true;
        }

        findmap[pos] = false;
        return false;
    }

    map<int, bool> findmap;
};
