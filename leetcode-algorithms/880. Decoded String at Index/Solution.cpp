// An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:
//
// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
// Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.
//
//
//
// Example 1:
//
// Input: S = "leet2code3", K = 10
// Output: "o"
// Explanation:
// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
// Example 2:
//
// Input: S = "ha22", K = 5
// Output: "h"
// Explanation:
// The decoded string is "hahahaha".  The 5th letter is "h".
// Example 3:
//
// Input: S = "a2345678999999999999999", K = 1
// Output: "a"
// Explanation:
// The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long len = 0;
        for (int i = 0; i < S.size(); i++) {
            auto c = S[i];
            if (('a' <= c) && (c <= 'z')) {
                len++;
                if (len == K) return string(1, c);
            } else {
                len *= c - '0';
                if (len >= K) {
                    return getval(S, i, len, K);
                }
            }
        }
    }

    string getval(string& S, int endp, long long len, int K) {
        for (int i = endp; i >= 0; i--) {
            char c = S[i];
            if (('a' <= c) && (c <= 'z')) {
                if (len == K) return string(1, S[i]);
                len--;
            } else {
                long long baselen = len / (c - '0');
                int k = (K - 1) % baselen + 1;
                return getval(S, i - 1, baselen, k);
            }
        }
    }
};
