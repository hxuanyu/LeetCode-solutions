// Given an input string , reverse the string word by word.
//
// Example:
//
// Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
// Note:
//
// A word is defined as a sequence of non-space characters.
// The input string does not contain leading or trailing spaces.
// The words are always separated by a single space.
// Follow up: Could you do it in-place without allocating extra space?
class Solution {
public:
    void reverseWords(vector<char>& str) {
        int a = 0;
        int b = str.size() - 1;
        while (a < b) swap(str[a++], str[b--]);

        a = 0;
        do {
            while ((a < str.size()) && (str[a] == ' ')) a++;
            if (a == str.size()) break;

            b = a;
            while ((b + 1 < str.size()) && (str[b + 1] != ' ')) b++;

            int ta = a;
            int tb = b;
            while (ta < tb) swap(str[ta++], str[tb--]);

            a = b + 1;
        } while (a < str.size());
    }
};
