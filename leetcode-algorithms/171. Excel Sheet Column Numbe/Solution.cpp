// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28
//     ...
// Example 1:
//
// Input: "A"
// Output: 1
// Example 2:
//
// Input: "AB"
// Output: 28
// Example 3:
//
// Input: "ZY"
// Output: 701
class Solution {
public:
    int titleToNumber(string s) {
        map<char, int> vmap;
        vmap['A'] = 1;
        vmap['B'] = 2;
        vmap['C'] = 3;
        vmap['D'] = 4;
        vmap['E'] = 5;
        vmap['F'] = 6;
        vmap['G'] = 7;
        vmap['H'] = 8;
        vmap['I'] = 9;
        vmap['J'] = 10;
        vmap['K'] = 11;
        vmap['L'] = 12;
        vmap['M'] = 13;
        vmap['N'] = 14;
        vmap['O'] = 15;
        vmap['P'] = 16;
        vmap['Q'] = 17;
        vmap['R'] = 18;
        vmap['S'] = 19;
        vmap['T'] = 20;
        vmap['U'] = 21;
        vmap['V'] = 22;
        vmap['W'] = 23;
        vmap['X'] = 24;
        vmap['Y'] = 25;
        vmap['Z'] = 26;

        int sum = 0;
        int base = 26;
        int times = 0;
        for (int i = s.size() - 1; i >= 0; i--, times++) {
            sum += vmap[s[i]] * pow(base, times);
        }
        return sum;
    }
};
