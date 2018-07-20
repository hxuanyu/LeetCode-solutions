// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
// Example 1:
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int, int> vmap1;
        for (auto v : s1) vmap1[v]++;

        map<int, int> vmap2;
        for (int i = 0; i < s1.length(); i++) vmap2[s2[i]]++;

        if (vmap1 == vmap2) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            vmap2[s2[i - s1.length()]]--;
            if (vmap2[s2[i - s1.length()]] == 0) vmap2.erase(s2[i - s1.length()]);
            vmap2[s2[i]]++;
            if (vmap1 == vmap2) return true;
        }

        return false;
    }
};
