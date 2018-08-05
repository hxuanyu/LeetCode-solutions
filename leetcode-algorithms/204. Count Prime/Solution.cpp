// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> bprime(n, true);
        bprime[1] = false;
        bprime[2] = true;
        bprime[3] = true;

        for (int i = 2; i <= sqrt(n); i++) {
            for (int j = i * i; j <= n; j += i) {
                bprime[j] = false;
            }
        }

        int count = 0;
        for (int i = 1; i < n; i++) {
            if (bprime[i]) count++;
        }

        return count;
    }
};
