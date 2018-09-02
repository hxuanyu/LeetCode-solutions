// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//
// Example 1:
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:
//
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:
//
// Can you solve it in O(N) time and O(1) space?
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> svec;
        stack<char> tvec;

        for (auto c : S) {
            if (('a' <= c) && (c <= 'z')) svec.push(c);
            else if (!svec.empty()) svec.pop();
        }

        for (auto c : T) {
            if (('a' <= c) && (c <= 'z')) tvec.push(c);
            else if (!tvec.empty()) tvec.pop();
        }

        if (svec.size() != tvec.size()) return false;

        while (!svec.empty()) {
            if (svec.top() != tvec.top()) return false;
            svec.pop();
            tvec.pop();
        }

        return true;
    }
};

// O(1) space complexity
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        spos = S.size() - 1;
        tpos = T.size() - 1;
        myS = S;
        myT = T;
        char s;
        char t;
        do {
            s = getnextchar(0);
            t = getnextchar(1);
            if (s != t) return false;
        } while ((s != 0) && (t != 0));

        return true;
    }

    char getnextchar(int id) {
        string str = (id == 0) ? myS : myT;
        int& pos = (id == 0) ? spos : tpos;

        while ((pos >= 0) && !(('a' <= str[pos]) && (str[pos] <= 'z'))) {
            int slen = 1;
            pos--;
            while ((pos >= 0) && (slen > 0)) {
                if (('a' <= str[pos]) && (str[pos] <= 'z')) slen--;
                else slen++;
                pos--;
            }
        }

        if (pos < 0) return 0;
        else return str[pos--];
     }


    int spos;
    int tpos;
    string myS;
    string myT;
};
