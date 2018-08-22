// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        vmap[make_pair(0, 0)] = grid[0][0];
        return getmin(grid, grid.size() - 1, grid[0].size() - 1);
    }

    int getmin(vector<vector<int>>& grid, int x, int y) {
        if (vmap.count(make_pair(x,y))) return vmap[make_pair(x, y)];

        int v = grid[x][y];
        if (x == 0) v += getmin(grid, x, y - 1);
        else if (y == 0) v += getmin(grid, x - 1, y);
        else v += min(getmin(grid, x, y - 1), getmin(grid, x - 1, y));

        vmap[make_pair(x, y)] = v;
        return v;
    }

    map<pair<int, int>, int> vmap;
};
