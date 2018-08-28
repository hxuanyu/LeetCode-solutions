// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int maxsize = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if ((grid[i][j] == 1) && (!visited[i][j])) {
                    int local = 0;
                    visit(grid, i, j, visited, local);
                    maxsize = max(maxsize, local);
                }
            }
        }
        return maxsize;
    }


    void visit(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, int& size) {
        int row = grid.size();
        int col = grid[0].size();
        if ((x < 0) || (y < 0) || (x >= row) || (y >= col) || (visited[x][y]) || (grid[x][y] != 1)) return;

        visited[x][y] = true;
        size++;
        vector<vector<int>> dirs={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto dir :dirs) {
            visit(grid, x + dir[0], y + dir[1], visited, size);
        }
    }
};
