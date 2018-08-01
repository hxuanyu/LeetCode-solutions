// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example:
// Given num = 16, return true. Given num = 5, return false.
//
// Follow up: Could you solve it without loops/recursion?
//
// Credits:
// Special thanks to @yukuairoy for adding this problem and creating all test cases.
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (int(sqrt(num)) * int(sqrt(num)) != num) return false;
        return isPowerOfTwo(sqrt(num));
    }

    bool isPowerOfTwo(int num) {
        if (num == 0) return false;

        int count = 0;
        while (num) {
            count++;
            num = num & (num - 1);
            if (count > 1) return false;
        }

        return true;
    }
};
