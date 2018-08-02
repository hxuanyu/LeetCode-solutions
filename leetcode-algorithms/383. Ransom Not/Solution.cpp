// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
//
// Each letter in the magazine string can only be used once in your ransom note.
//
// Note:
// You may assume that both strings contain only lowercase letters.
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        map<char, int> amap;
        for (auto c : ransomNote) amap[c]++;

        map<char, int> bmap;
        for (auto c : magazine) bmap[c]++;

        for (auto item : amap) {
            if (!bmap.count(item.first)) return false;
            if (item.second > bmap[item.first]) return false;
        }

        return true;
    }
};
