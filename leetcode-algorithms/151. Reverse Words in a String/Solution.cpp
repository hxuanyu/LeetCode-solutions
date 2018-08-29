// Given an input string, reverse the string word by word.
//
// Example:
//
// Input: "the sky is blue",
// Output: "blue is sky the".
// Note:
//
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// You need to reduce multiple spaces between two words to a single space in the reversed string.
// Follow up: For C programmers, try to solve it in-place in O(1) space.
class Solution {
public:
    void reverseWords(string& s) {
        int a = 0;
        int i = -1;
        bool bfirst = true;
        do {
            while ((a < s.size()) && (s[a] == ' ')) a++;
            if (a == s.size()) break;

            int b = a;
            while ((b + 1 < s.size()) && (s[b + 1] != ' ')) b++;

            int ta = a;
            int tb = b;
            while (ta < tb) {
                swap(s[ta], s[tb]);
                ta++;
                tb--;
            }

            if (bfirst) {
                bfirst = false;
                i += 1;
            } else {
                s[i + 1] = ' ';
                i += 2;
            }

            for (int len = 0; len <= b - a; len++) {
                s[i + len] = s[a + len];
            }

            i += b - a;
            a = b + 1;
        } while (a < s.size());

        s = s.substr(0, i + 1);
        a = 0;
        int b = s.size() - 1;
        while (a < b) swap(s[a++], s[b--]);
    }
};
