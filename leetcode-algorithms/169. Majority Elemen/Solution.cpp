// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
//     ...
// Example 1:
//
// Input: 1
// Output: "A"
// Example 2:
//
// Input: 28
// Output: "AB"
// Example 3:
//
// Input: 701
// Output: "ZY"
class Solution {
public:
    string convertToTitle(int n) {
        vector<char> vec(26, ' ');
        vec[0] = 'A';
        vec[1] = 'B';
        vec[2] = 'C';
        vec[3] = 'D';
        vec[4] = 'E';
        vec[5] = 'F';
        vec[6] = 'G';
        vec[7] = 'H';
        vec[8] = 'I';
        vec[9] = 'J';
        vec[10] = 'K';
        vec[11] = 'L';
        vec[12] = 'M';
        vec[13] = 'N';
        vec[14] = 'O';
        vec[15] = 'P';
        vec[16] = 'Q';
        vec[17] = 'R';
        vec[18] = 'S';
        vec[19] = 'T';
        vec[20] = 'U';
        vec[21] = 'V';
        vec[22] = 'W';
        vec[23] = 'X';
        vec[24] = 'Y';
        vec[25] = 'Z';

        string rslt = "";
        while (n) {
            rslt = vec[(n - 1)% 26] + rslt;
            n = (n - 1) / 26;
        }

        return rslt;
    }
};
