// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//
// Example 1:
//
// Given input matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:
//
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;

        int n = matrix[0].size();
        if (n == 0) return;

        int startrow = 0;
        int endrow = m - 1;
        int startcol = 0;
        int endcol = n - 1;

        while ((startrow < endrow) && (startcol < endcol)) {
            int width = endcol - startcol + 1;
            for (int i = 0; i < width - 1; i ++) {
                swap(matrix[startrow][endcol - i], matrix[endrow - i][endcol]);
            }

            for (int i = 0; i < width - 1; i++) {
                swap(matrix[startrow][endcol - i], matrix[startrow + i][startcol]);
            }

            for (int i = 0; i < width - 1; i++) {
                swap(matrix[endrow][endcol - 1 - i], matrix[endrow - 1 - i][startcol]);
            }

            startrow++;
            endrow--;
            startcol++;
            endcol--;
        }
    }
};
