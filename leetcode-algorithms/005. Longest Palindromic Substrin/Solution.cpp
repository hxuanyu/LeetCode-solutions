// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
//
// Input: "cbbd"
// Output: "bb"
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int maxlen = INT_MIN;
        int pos = -1;
        for (int i = 0; i < s.size(); i++) {
            int len = 1;
            int c = i;

            while ((c + 1 < s.size()) && (s[c + 1] == s[i])) {
                c++;
                len++;
            }

            int left = i;
            int right = c;

            while ((left - 1 >= 0) && (right + 1 < s.size()) && (s[left - 1] == s[right + 1])) {
                len += 2;
                left--;
                right++;
            }

            if (len > maxlen) {
                pos = left;
                maxlen = len;
            }
        }

        return s.substr(pos, maxlen);
    }
};

// a dp solution
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int size = s.size();
        vector<vector<bool>> bpar(size, vector<bool>(size, false));

        int maxlen = 1;
        int pos = 0;
        for (int i = 0; i < size; i++) bpar[i][i] = true;
        for (int i = 0; i < size - 1; i++) {
            if (bpar[i][i + 1] = (s[i] == s[i + 1])) {
                maxlen = 2;
                pos = i;
            }
        }

        for (int len = 3; len <= size; len++) {
            for (int i = 0; i < size; i++) {
                int j = i + len - 1;
                if (j >= size) continue;

                if ((bpar[i][j] = (s[i] == s[j]) && bpar[i + 1][j - 1]) && (j - i + 1 > maxlen)) {
                    maxlen = j - i + 1;
                    pos = i;
                }
            }
        }

        return s.substr(pos, maxlen);
    }
};
