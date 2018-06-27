// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:
//
// Input: "race a car"
// Output: false

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            char a = s[start];
            char b = s[end];
            if (!isalpha(a)) {
                start++;
                continue;
            }
            if (!isalpha(b)) {
                end--;
                continue;
            }

            if (a != b) return false;
            start++;
            end--;
        }

        return true;
    }

    bool isalpha(char& c) {
        if ((c >= 'a') && (c <= 'z')) {
            return true;
        }

        if ((c >= 'A') && (c <= 'Z')) {
            c = c -'A' + 'a';
            return true;
        }

        if ((c >= '0') && (c <= '9')) return true;

        return false;
    }
};
