// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
// Input: 16
// Returns: True
// Example 2:
//
// Input: 14
// Returns: False
// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        int a = 1;
        int b = num;
        long long num_ = num;

        while (a <= b) {
            int mid = a + (b - a) / 2;
            if ((num % mid == 0) && (num / mid == mid)) return true;
            else if (num_ > (long long)(mid) * (long long)(mid)) a = mid + 1;
            else b = mid - 1;
        }

        return false;
    }
};
