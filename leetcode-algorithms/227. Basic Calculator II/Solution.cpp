// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
// Example 1:
//
// Input: "3+2*2"
// Output: 7
// Example 2:
//
// Input: " 3/2 "
// Output: 1
// Example 3:
//
// Input: " 3+5 / 2 "
// Output: 5
// Note:
//
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

class Solution {
public:
    int calculate(string s) {
        int total = 0;
        bool bPositive = true;
        stack<int> v;
        char lastop = ' ';

        for (int i = 0; i < s.length(); ) {
            if (s[i] == ' ') {
                i++;
            } else if ((s[i] == '+') || (s[i] == '-')) {
                bPositive = s[i] == '+';
                lastop = ' ';
                i++;
            } else if ((s[i] == '*') || (s[i] =='/')) {
                lastop = s[i];
                i++;
            } else {
                int p = i;
                int current = 0;
                while ((p < s.length()) && (('0' <= s[p]) && (s[p] <= '9'))) {
                    current = 10 * current + s[p] - '0';
                    p++;
                }

                if (lastop == ' ') {
                    current = bPositive ? current : -current;
                } else if (lastop == '*') {
                    current = v.top() * current;
                    v.pop();
                } else if (lastop == '/') {
                    current = v.top() / current;
                    v.pop();
                }
                v.push(current);
                i = p;
            }
        }

        while (!v.empty()) {
            total += v.top();
            v.pop();
        }
        return total;
    }
};
