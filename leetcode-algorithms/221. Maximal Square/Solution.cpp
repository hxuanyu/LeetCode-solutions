// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
// Input:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;

        vector<vector<int>> len(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++) len[i][0] = (matrix[i][0] == '1') ? 1 : 0;
        for (int j = 0; j < col; j++) len[0][j] = (matrix[0][j] == '1') ? 1 : 0;

        int maxlen = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (len[i][j] == -1) {
                    if (matrix[i][j] == '0') len[i][j] = 0;
                    else {
                        len[i][j] = min(min(len[i - 1][j], len[i][j - 1]), len[i - 1][j - 1]) + 1;
                    }
                }
                maxlen = max(maxlen, len[i][j]);
            }
        }

        return maxlen * maxlen;
    }
};
