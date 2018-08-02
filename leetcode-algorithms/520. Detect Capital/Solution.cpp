// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
class Solution {
public:
    bool detectCapitalUse(string word) {
        int ucount = 0;
        int lcount = 0;
        for (auto c : word) {
            if (('a' <= c) && (c <= 'z')) lcount++;
            else if (('A' <= c) && (c <= 'Z')) ucount++;
        }

        if ((ucount == word.size()) || (lcount == word.size())) return true;
        if ((word.size() > 1) && (ucount == 1) && (('A' <= word[0]) && (word[0] <= 'Z'))) return true;
        return false;
    }
};
