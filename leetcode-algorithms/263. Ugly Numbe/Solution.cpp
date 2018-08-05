// Write a program to check whether a given number is an ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
// Example 1:
//
// Input: 6
// Output: true
// Explanation: 6 = 2 × 3
// Example 2:
//
// Input: 8
// Output: true
// Explanation: 8 = 2 × 2 × 2
// Example 3:
//
// Input: 14
// Output: false
// Explanation: 14 is not ugly since it includes another prime factor 7.
// Note:
//
// 1 is typically treated as an ugly number.
// Input is within the 32-bit signed integer range: [−231,  231 − 1].
class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) return true;
        else if (num <= 0) return false;

        set<int> se = {2, 3, 5};
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                if (((i != 1) && (bprime(i) && !se.count(i)) ||  (bprime(num / i) && !se.count(num / i)))) return false;
            }
        }
        return true;
    }

    bool bprime(int num) {
        if (num == 1) return false;
        else if ((num == 2) || (num == 3)) return true;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
};
