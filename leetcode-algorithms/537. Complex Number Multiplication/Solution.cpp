// Given two strings representing two complex numbers.
//
// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//
// Example 1:
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
// Note:
//
// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int areal;
        int acomp;
        parse(a, areal, acomp);

        int breal;
        int bcomp;
        parse(b, breal, bcomp);

        string rslt;
        rslt += std::to_string(areal * breal - acomp * bcomp);
        rslt += '+';
        rslt += std::to_string(areal * bcomp + acomp * breal);
        rslt += 'i';
        return rslt;
    }

    void parse(string str, int& real, int& comp) {
        bool realpositive = true;
        if ((str[0] == '+') || (str[0] == '-')) {
            realpositive = str[0] == '+';
            str = str.substr(1, string::npos);
        }

        std:size_t pos = str.find('+');
        string sreal = str.substr(0, pos);
        string scom = str.substr(pos + 1, string::npos);
        real = realpositive ? stoi(sreal.substr(0, string::npos)) : -stoi(sreal.substr(0, string::npos));

        comp = 0;
        if ((scom[0] == '+') || (scom[0] == '-')) {
            comp = (scom[0] == '+') ? stoi(scom.substr(1, string::npos - 1)) : -stoi(scom.substr(1, string::npos - 1));
        } else {
            comp = stoi(scom.substr(0, string::npos - 1));
        }
    }
};
