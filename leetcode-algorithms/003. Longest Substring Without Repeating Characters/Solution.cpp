// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
//
// Input: a = "1010", b = "1011"
// Output: "10101"
class Solution {
public:
    string addBinary(string a, string b) {
        int posa = a.length() - 1;
        int posb = b.length() - 1;

        int carrage = 0;
        int sum = 0;
        string rslt;
        while ((posa >= 0) || (posb >= 0)) {
            sum = carrage;
            if (posa >= 0) sum += (a[posa--] - '0');
            if (posb >= 0) sum += (b[posb--] - '0');
            rslt = std::to_string(sum % 2) + rslt;
            carrage = sum / 2;
        }

        if (carrage) rslt = '1' + rslt;
        return rslt;
    }
};
