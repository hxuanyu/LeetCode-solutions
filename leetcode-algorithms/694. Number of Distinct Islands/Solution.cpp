// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
//
// Example 1:
// 11000
// 11000
// 00011
// 00011
// Given the above grid map, return 1.
// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.
//
// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered different island shapes, because we do not consider reflection / rotation.
// Note: The length of each dimension in the given grid does not exceed 50.
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        set<vector<pair<int, int>>> shapeset;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((!visited[i][j]) && (grid[i][j] == 1)) {
                    vector<pair<int, int>> shape;
                    visit(grid, i, j, i, j, visited, shape);
                    shapeset.insert(shape);
                }
            }
        }
        return shapeset.size();
    }

    void visit(vector<vector<int>>& grid, int i, int j, int ori, int orj, vector<vector<bool>>& visited, vector<pair<int, int>>& shape) {
        if ((i < 0) || (j < 0) || (i >= grid.size()) || (j >= grid[0].size()) || (visited[i][j]) || (grid[i][j] == 0)) return;

        visited[i][j] = true;
        shape.push_back(make_pair(i - ori, j - orj));

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto dir : dirs) {
            visit(grid, i + dir[0], j + dir[1], ori, orj, visited, shape);
        }
    }
};
