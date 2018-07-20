// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
//
// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vecs(26, 0);
        vector<int> vect(26, 0);

        for (auto v : s) vecs[v - 'a']++;
        for (auto v : t) vect[v - 'a']++;

        return vecs == vect;
    }
};
