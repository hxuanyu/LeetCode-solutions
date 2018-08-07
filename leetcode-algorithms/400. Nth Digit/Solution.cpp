// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
//
// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
// Example 1:
//
// Input:
// 3
//
// Output:
// 3
// Example 2:
//
// Input:
// 11
//
// Output:
// 0
//
// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        int t = 1;

        do {
            if (n <= 9 * pow(10, t - 1) * t) break;
            n -= 9 * pow(10, t - 1) * t;
            t++;
        } while (true);

        int nthint = (n - 1) / t;
        int v = pow(10, t - 1) + nthint;
        int dig = (n - 1) % t;

        int div = pow(10, t - 1);
        int tv;
        do {
            tv = v / div;
            v %= div;
            dig--;
            div /= 10;
        } while (dig >= 0);

        return tv;
    }
};
