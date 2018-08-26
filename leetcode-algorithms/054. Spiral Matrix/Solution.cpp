// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rslt;
        int startrow = 0;
        int endrow = matrix.size() - 1;
        if (endrow == -1) return rslt;
        int startcol = 0;
        int endcol = matrix[0].size() - 1;
        if (endcol == -1) return rslt;

        do {
            for (int j = startcol; j <= endcol; j++) rslt.push_back(matrix[startrow][j]);
            if (startrow == endrow) break;
            for (int i = startrow + 1; i <= endrow; i++) rslt.push_back(matrix[i][endcol]);
            if (startcol == endcol) break;
            for (int j = endcol - 1; j >= startcol; j--) rslt.push_back(matrix[endrow][j]);
            for (int i = endrow - 1; i >= startrow + 1; i--) rslt.push_back(matrix[i][startcol]);
            startrow++;
            endrow--;
            startcol++;
            endcol--;
        } while ((startrow <= endrow) && (startcol <= endcol));
        return rslt;
    }
};
