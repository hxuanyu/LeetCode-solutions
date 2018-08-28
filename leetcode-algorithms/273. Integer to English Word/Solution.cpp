// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
// Example 1:
//
// Input: 123
// Output: "One Hundred Twenty Three"
// Example 2:
//
// Input: 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:
//
// Input: 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Example 4:
//
// Input: 1234567891
// Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
class Solution {
public:
    string numberToWords(int num) {
        //1000000000, 1000000, 1000, 100;
        if (num < 20) return onemap[num];
        else if (num < 100) return tenmap[num / 10] + (num % 10 == 0 ? "" : " " + numberToWords(num % 10));
        else if (num < 1000) return onemap[num / 100] + " Hundred" + (num % 100 == 0 ? "" : " " + numberToWords(num % 100));
        else if (num < 1000000) return numberToWords(num / 1000) + " Thousand" + (num % 1000 == 0 ? "" : " " + numberToWords(num % 1000));
        else if (num < 1000000000) return numberToWords(num / 1000000) + " Million" + (num % 1000000 == 0 ? "" : " " + numberToWords(num % 1000000));
        else return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 == 0 ? "" : " " + numberToWords(num % 1000000000));
    }

    map<int, string> onemap = { { 0, "Zero" },{ 1,"One" },{ 2,"Two" },{ 3,"Three" },{ 4,"Four" },{ 5,"Five" },{ 6,"Six" },{ 7,"Seven" },{ 8, "Eight" },{ 9,"Nine" },{ 10,"Ten" },
    { 11,"Eleven" },{ 12,"Twelve" },{ 13, "Thirteen" },{ 14, "Fourteen" },{ 15, "Fifteen" },{ 16, "Sixteen" },{ 17, "Seventeen" },{ 18, "Eighteen" },{ 19, "Nineteen" } };
    map<int, string> tenmap = { { 2, "Twenty" },{ 3, "Thirty" },{ 4, "Forty" },{ 5, "Fifty" },{ 6, "Sixty" },{ 7, "Seventy" },{ 8, "Eighty" },{ 9, "Ninety" } };
};
