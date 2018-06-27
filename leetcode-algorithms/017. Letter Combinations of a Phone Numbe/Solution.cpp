// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rslt;
        if (digits.length() == 0) return rslt;
        map<char, vector<char>> vmap;
        vmap['2'] = {'a', 'b', 'c'};
        vmap['3'] = {'d', 'e', 'f'};
        vmap['4'] = {'g', 'h', 'i'};
        vmap['5'] = {'j', 'k', 'l'};
        vmap['6'] = {'m', 'n', 'o'};
        vmap['7'] = {'p', 'q', 'r', 's'};
        vmap['8'] = {'t', 'u', 'v'};
        vmap['9'] = {'w', 'x', 'y', 'z'};

        string temp;
        perm(digits, 0, vmap, temp, rslt);
        return rslt;
    }

    void perm(string digits, int pos, map<char, vector<char>>& vmap, string& temp, vector<string>& rslt) {
        if (pos == digits.length()) {
            if (temp.length() == digits.length()) rslt.push_back(temp);
            return;
        }

        for (int i = pos; i < digits.length(); i++) {
            for (int j = 0; j < vmap[digits[i]].size(); j++) {
                temp += vmap[digits[i]][j];
                perm(digits, i + 1, vmap, temp, rslt);
                temp = temp.substr(0, temp.length() - 1);
            }
        }
    }
};
