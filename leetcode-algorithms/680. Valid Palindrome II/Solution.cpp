// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
//
// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
class Solution {
public:
    bool validPalindrome(string s, bool alloneerror = true) {
        int a = 0;
        int b = s.length() - 1;
        int count = 0;

        while (a < b) {
            if (s[a] != s[b]) {
                if (alloneerror) return validPalindrome(s.substr(a+1, b-a), false) || validPalindrome(s.substr(a, b-a), false);
                else return false;
            }
            a++;
            b--;
        }

        return true;
    }
};
