// Given a string, your task is to count how many palindromic substrings in this string.
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// Note:
// The input string length won't exceed 1000.
class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        if (size <= 1) return size;


        vector<vector<bool>> bpar(size, vector<bool>(size, false));

        int count = 0;
        for (int i = 0; i < size; i++) bpar[i][i] = true;
        count += size;
        for (int i = 0; i < size - 1; i++) {
            if (bpar[i][i + 1] = (s[i] == s[i + 1])) count++;
        }


        for (int len = 3; len <= size; len++) {
            for (int i = 0; i < size; i++) {
                int j = i + len - 1;
                if (j >= size) continue;

                if (bpar[i][j] = (s[i] == s[j]) && bpar[i + 1][j - 1]) count++;
            }
        }

        return count;
    }
};
