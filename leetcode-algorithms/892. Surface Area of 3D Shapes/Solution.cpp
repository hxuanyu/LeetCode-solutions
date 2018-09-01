// On a N * N grid, we place some 1 * 1 * 1 cubes.
//
// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
//
// Return the total surface area of the resulting shapes.
//
// Example 1:
//
// Input: [[2]]
// Output: 10
// Example 2:
//
// Input: [[1,2],[3,4]]
// Output: 34
// Example 3:
//
// Input: [[1,0],[0,2]]
// Output: 16
// Example 4:
//
// Input: [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32
// Example 5:
//
// Input: [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46
//
//
// Note:
//
// 1 <= N <= 50
// 0 <= grid[i][j] <= 50
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        map<int, int> colmax;
        map<int, int> rowmax;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) count++;
            }
        }

        int rowface = 0;
        for (int i = 0; i < grid.size(); i++) {
            rowface += grid[i][0];
            rowface += grid[i].back();

            for (int j = 1; j < grid[i].size(); j++) {
                rowface += abs(grid[i][j] - grid[i][j - 1]);
            }
        }

        int colface = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            colface += grid[0][j];
            colface += grid[grid.size() - 1][j];
            for (int i = 1; i < grid.size(); i++) {
                colface += abs(grid[i][j] - grid[i - 1][j]);
            }
        }

        int total = count * 2;
        total += rowface;
        total += colface;
        return total;
    }
};
