// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
// Input: 121
// Output: true
// Example 2:
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:
//
// Coud you solve it without converting the integer to a string?
class Solution {
public:

    bool isPalindrome(int x) {
        if (x < 0) return false;

        int pos = 0;
        map<int, int> pos_to_val;
        while (x) {
            pos_to_val[pos] = x % 10;
            x /= 10;
            pos++;
        }

        map<int,int>::iterator iter = pos_to_val.begin();

        int len = pos;
        for (; iter != pos_to_val.end(); iter++) {
            int pos = iter->first;
            int val = iter->second;

            int target = len - 1 - pos;
            if (pos_to_val[pos] != pos_to_val[target]) return false;
        }

        return true;
    }

    bool isPalindrome1(int x) {
        if (x < 0) return false;

        vector<int> vec;
        while (x) {
            vec.push_back(x % 10);
            x /= 10;
        }

        vector<int> back(vec);
        reverse(vec.begin(), vec.end());
        return vec == back;
    }
};
