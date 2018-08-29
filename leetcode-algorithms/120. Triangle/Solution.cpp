// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

// bottom up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 0) return 0;
        else if (row == 1) return triangle[0][0];

        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

// top down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> mins;
        for (auto row : triangle) mins.push_back(vector<int>(row.size(), 0));
        mins[0][0] = triangle[0][0];

        int row = triangle.size();
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j >= triangle[i - 1].size()) mins[i][j] = mins[i - 1][j - 1] + triangle[i][j];
                else if (j == 0) mins[i][j] = mins[i - 1][j] + triangle[i][j];
                else mins[i][j] = min(mins[i - 1][j - 1], mins[i - 1][j]) + triangle[i][j];
            }
        }

        int minv = INT_MAX;
        for (auto v : mins[row - 1]) {
            minv = min(minv, v);
        }

        return minv;
    }
};
