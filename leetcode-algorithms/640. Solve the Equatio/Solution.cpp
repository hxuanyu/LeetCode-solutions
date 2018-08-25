// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.
//
// If there is no solution for the equation, return "No solution".
//
// If there are infinite solutions for the equation, return "Infinite solutions".
//
// If there is exactly one solution for the equation, we ensure that the value of x is an integer.
//
// Example 1:
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"
// Example 2:
// Input: "x=x"
// Output: "Infinite solutions"
// Example 3:
// Input: "2x=x"
// Output: "x=0"
// Example 4:
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"
// Example 5:
// Input: "x=x+2"
// Output: "No solution"

class Solution {
public:
    string solveEquation(string equation) {
        std::size_t pos = equation.find('=');
        if (pos == string::npos) return "No solution";

        int coeleft = 0;
        int valleft = 0;
        int coeright = 0;
        int valright = 0;
        findp(equation.substr(0, pos), coeleft, valleft);
        findp(equation.substr(pos + 1, string::npos), coeright, valright);

        if (valleft == valright) {
            if (coeleft != coeright) return "x=0";
            else return "Infinite solutions";
        } else {
            if (coeleft == coeright) return "No solution";
            else return "x=" + std::to_string((valright - valleft) / (coeleft - coeright));
        }
    }

    void findp(string str, int& coe, int& val) {
        string strval = "";
        bool bpositive = true;

        coe = 0;
        val = 0;

        for (auto c : str) {
            if ((c == '+') || (c == '-')) {
                if (strval.size() != 0) {
                    if (strval.find('x') == string::npos) {
                        if (bpositive) val += stoi(strval);
                        else val -= stoi(strval);
                    } else {
                        strval = strval.substr(0, strval.size() - 1);
                        int val = strval.size() == 0 ? 1 : stoi(strval);

                        if (bpositive) coe += val;
                        else coe -= val;
                    }
                }
                bpositive = c == '+';
                strval = "";
                continue;
            }

            strval += c;
        }

        if (strval.size() != 0) {
            if (strval.find('x') == string::npos) {
                if (bpositive) val += stoi(strval);
                else val -= stoi(strval);
            } else {
                strval = strval.substr(0, strval.size() - 1);
                int val = strval.size() == 0 ? 1 : stoi(strval);

                if (bpositive) coe += val;
                else coe -= val;
            }
        }
    }
};
