// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
class Solution {
public:
    int numDecodings(string s) {
        return getways(s);
    }

    int getways(string s) {
        if (vmap.count(s)) return vmap[s];
        int v = 0;
        if (s.size() == 0) return 1;
        else if (s.size() == 1) return s != "0" ? 1 : 0;
        else {
            if (('3' <= s[0]) && (s[0] <= '9')) v = getways(s.substr(1, string::npos));
            else {
                if (s[0] == '1') {
                    v = getways(s.substr(1, string::npos)) + getways(s.substr(2, string::npos));
                } else if (s[0] == '2') {
                    v = getways(s.substr(1, string::npos));
                    if (('0' <= s[1]) && (s[1] <= '6')) v += getways(s.substr(2, string::npos));
                } else if (s[0] == '0') {
                    v = 0;
                }
            }
        }

        vmap[s] = v;
        return v;
    }

    map<string, int> vmap;
};
