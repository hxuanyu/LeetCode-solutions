// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
// Example 1:
//
// Input: "1 + 1"
// Output: 2
// Example 2:
//
// Input: " 2-1 + 2 "
// Output: 3
// Example 3:
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.
class Solution {
public:
    int calculate(string s) {
        bool bpositive = true;
        string str = "";
        vector<vector<int>> vals;
        vals.push_back({});

        vector<bool> rangepositive;
        rangepositive.push_back(true);

        for (auto c : s) {
            if (c == ' ') continue;

            if (c == '(') {
                vals.push_back({});
                str = "";
                rangepositive.push_back(bpositive);
                bpositive = true;
            } else if ((c == '+') || (c == '-') || (c == ')')) {
                if (str.size() > 0) {
                    if (bpositive) {
                        vals.back().push_back(stoi(str));
                    } else {
                        vals.back().push_back(-stoi(str));
                    }
                }
                if (c == '+') bpositive = true;
                else if (c == '-') bpositive = false;
                else if (c == ')') {
                    int total = 0;
                    for (auto c : vals.back()) {
                        total += c;
                    }
                    vals.pop_back();
                    vals.back().push_back(rangepositive.back() ? total : -total);
                    rangepositive.pop_back();
                }

                str = "";
            } else str += c;
        }


        if (str.size() > 0) {
            if (bpositive) {
                vals.back().push_back(stoi(str));
            } else {
                vals.back().push_back(-stoi(str));
            }
        }

        int total = 0;
        for (auto c : vals.back()) total += c;
        return total;
    }
};
