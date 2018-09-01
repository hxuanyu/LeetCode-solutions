// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
// Example:
//
// Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Output:
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> vmap;

        for (auto s : strings) {
            vmap[getkey(s)].push_back(s);
        }

        vector<vector<string>> rslt;
        for (auto item : vmap) rslt.push_back(item.second);

        return rslt;
    }

    string getkey(string s) {
        for (int i = 1; i < s.size(); i++) {
            s[i] = ((s[i] - s[0] < 0) ? (s[i] - s[0] + 26) : (s[i] - s[0])) + '0';
        }
        s[0] = '0';
        return s;
    }
};
