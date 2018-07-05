// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
class Solution {
    public int numIslands(char[][] grid) {
        if ((grid.length == 0) || (grid[0].length == 0)) return 0;
        int count = 0;
        boolean visited[][] = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if ((grid[i][j] == '1') && (!visited[i][j])) {
                    visit(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }

    public void visit(char[][] grid, int x, int y, boolean[][] visited) {
        if ((x < 0) || (x >= grid.length) || (y < 0) || (y >= grid[0].length) || visited[x][y] || (grid[x][y] != '1')) return;

        visited[x][y] = true;

        int dirs [][] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int[] dir : dirs) {
            int newx = x + dir[0];
            int newy = y + dir[1];
            visit(grid, newx, newy, visited);
        }
    }
}
