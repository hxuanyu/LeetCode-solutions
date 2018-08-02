// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
// Example:
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> countmap;
        int len = 0;
        for (auto c : s) {
            countmap[c]++;
        }

        map<char, int>::iterator iter = countmap.begin();
        bool noodd = true;
        for (; iter != countmap.end(); iter++) {
            if (iter->second % 2 == 0) len += iter->second;
            else noodd = false;
        }

        if (noodd) return len;

        for (iter = countmap.begin(); iter != countmap.end(); iter++) {
            if (iter->second % 2 != 0) len += (iter->second - 1);
        }

        return len + 1;
    }
};
