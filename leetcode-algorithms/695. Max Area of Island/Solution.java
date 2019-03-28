class Solution {
    public int maxAreaOfIsland(int[][] grid) {
    	int row = grid.length;
    	if (row == 0) return 0;
    	int col = grid[0].length;
    	if (col == 0) return 0;

        boolean [][] visited = new boolean[row][col];
        int [] area = new int[1];
        int maxv = 0;
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
        		if (!visited[i][j] && (grid[i][j] == 1)) {
        			clearvisited(visited);
        			area[0] = 0;
        			visit(grid, i, j, visited, area);
        			maxv = Math.max(area[0], maxv);
        		}
        	}
        }

        return maxv;
    }

    private void clearvisited(boolean [][] visited) {
    	for (int i = 0; i < visited.length; i++) {
    		for (int j = 0; j < visited[0].length; j++) {
    			visited[i][j] = false;
    		}
    	}
    }

    private void visit(int[][] grid, int i, int j, boolean[][] visited, int[] area) {
    	int row = grid.length;
    	int col = grid[0].length;
    	if ((i < 0) || (i >= row) || (j < 0) || (j >= col) || visited[i][j] || (grid[i][j] != 1)) return;

    	visited[i][j] = true;
    	area[0]++;
    	int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    	for (int[] dir : dirs) {
    		visit(grid, i + dir[0], j + dir[1], visited, area);
    	}
    }
}
