// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
//
// Note:
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
// Example 1:
// Input: 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:
// Input: 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
class Solution {
public:
    int findComplement(int num) {
        int rslt = 0;

        int p = 1;
        while (num) {
            int d = num % 2;
            if (d == 0) d = 1;
            else if (d == 1) d = 0;
            rslt += (p * d);
            p *= 2;
            num = num / 2;
        }

        return rslt;
    }
};
