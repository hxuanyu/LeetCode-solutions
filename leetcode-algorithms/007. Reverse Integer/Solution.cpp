// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
// Input: 123
// Output: 321
// Example 2:
//
// Input: -123
// Output: -321
// Example 3:
//
// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        bool bnegative = x < 0;
        long long v = x;
        if (bnegative) v = -v;

        int rslt = reverse(v, bnegative);
        return bnegative ? -rslt: rslt;
    }

    long long reverse(long long v, bool bnegative) {
        long long rslt = 0;
        while (v) {
            rslt = rslt * 10 + v % 10;
            if (!bnegative && (rslt > INT_MAX)) return 0;
            else if (bnegative && (rslt - 1 > INT_MAX)) return 0;
            v /= 10;
        }

        return rslt;
    }
};
