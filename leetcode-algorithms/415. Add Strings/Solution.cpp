// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() == 0) return num2;
        else if (num2.size() == 0) return num1;

        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;

        string rslt = "";
        int sum = 0;
        int carrage = 0;
        while (p1 >= 0 || p2 >= 0) {
            sum = carrage;
            if (p1 >= 0) sum += (num1[p1] - '0');
            if (p2 >= 0) sum += (num2[p2] - '0');
            carrage = sum / 10;
            rslt = std::to_string(sum % 10) + rslt;
            p1--;
            p2--;
        }

        if (carrage) rslt = "1" + rslt;

        return rslt;
    }
};
