// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if (obstacleGrid[row - 1][col - 1] == 1) return 0;
        if (obstacleGrid[0][0] == 1) return 0;

        ways[make_pair(0, 0)] = 1;
        return getimpl(obstacleGrid, row - 1, col - 1);
    }

    int getimpl(vector<vector<int>>& obstacleGrid, int x, int y) {
        if ((x < 0) || (y < 0)) return 0;
        if (ways.count(make_pair(x, y))) return ways[make_pair(x, y)];

        int total = 0;
        if ((y >= 1) && (obstacleGrid[x][y - 1] == 0)) total += getimpl(obstacleGrid, x, y - 1);
        if ((x >= 1) && (obstacleGrid[x - 1][y] == 0)) total += getimpl(obstacleGrid, x - 1, y);
        ways[make_pair(x, y)] = total;
        return total;
    }

    map<pair<int, int>, int> ways;
};
