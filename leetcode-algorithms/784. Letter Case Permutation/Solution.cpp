// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
//
// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
// Input: S = "3z4"
// Output: ["3z4", "3Z4"]
//
// Input: S = "12345"
// Output: ["12345"]
// Note:
//
// S will be a string with length at most 12.
// S will consist only of letters or digits.
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        string temp;
        vector<string> rslt;
        perm(S, 0, temp,rslt);
        return rslt;
    }

    void perm(string& s, int pos, string& temp, vector<string>& rslt) {
        if (pos == s.length() && (temp.length() == s.length())) {
            rslt.push_back(temp);
            return;
        }

        vector<char> vec;
        char c = s[pos];
        char nc;
        vec.push_back(c);
        if (isletter(s[pos])) {
            if ((c >= 'a') && (c <= 'z')) nc = c - 'a' + 'A';
            else nc = c - 'A' + 'a';
            vec.push_back(nc);
        }


        for (auto c:vec) {
            temp += c;
            perm(s, pos + 1, temp, rslt);
            temp = temp.substr(0, temp.length() - 1);
        }
    }

    bool isletter(char c) {
        return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
    }
};
