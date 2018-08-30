// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input:
//
// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:
//
// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        if (size <= 1) return size;

        int maxlen = 1;
        vector<vector<int>> lens(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) lens[i][i] = 1;
        for (int i = 0; i < size - 1; i++) {
            lens[i][i + 1] = (s[i] == s[i + 1]) ? 2 : 1;
            maxlen = max(maxlen, lens[i][i + 1]);
        }

        for (int len = 3; len <= size; len++) {
            for (int i = 0; i < size; i++) {
                int j = i + len - 1;
                if (j >= size) continue;

                if (s[i] == s[j]) lens[i][j] = lens[i + 1][j - 1] + 2;
                else lens[i][j] = max(lens[i][j - 1], lens[i + 1][j]);
                maxlen = max(maxlen, lens[i][j]);
            }
        }

        return maxlen;
    }
};
