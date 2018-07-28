// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
//
// Example 1:
//
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//
// Note:
//
// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        map<int, int> vmap;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) vmap[i] = 0;
        }

        while (vmap.size() != S.length()) {
            map<int, int> newmap;

            for (auto item : vmap) {
                int pos = item.first;
                int val = item.second;
                if ((pos - 1 >= 0) && (vmap.count(pos - 1) == 0)) {
                    if (newmap.count(pos - 1) == 0) newmap[pos - 1] = val + 1;
                    else newmap[pos - 1] = min(val + 1, newmap[pos - 1]);
                }

                if ((pos + 1 < S.length()) && (vmap.count(pos + 1) == 0)) {
                    if (newmap.count(pos + 1) == 0) newmap[pos + 1] = val + 1;
                    else newmap[pos + 1] = min(val + 1, newmap[pos + 1]);
                }
            }

            for (auto newitem : newmap) {
                vmap[newitem.first] = newitem.second;
            }
        }

        vector<int> rslt(S.length());
        for (auto item : vmap) rslt[item.first] = item.second;

        return rslt;
    }
};
