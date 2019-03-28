class Solution {
    public int maximalSquare(char[][] matrix) {
        int row = matrix.length;
        if (row == 0) return 0;

        int col = matrix[0].length;
        if (col == 0) return 0;

        int max = 0;
        int [][] maxv = new int[row][col];
        for (int i = 0; i < row; i++) {
            maxv[i][0] = matrix[i][0] == '1' ? 1 : 0;
            max = Math.max(maxv[i][0], max);
        }
        for (int j = 0; j < col; j++) {
            maxv[0][j] = matrix[0][j] == '1' ? 1 : 0;
            max = Math.max(maxv[0][j], max);
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '0') continue;
                maxv[i][j] = 1 + Math.min(Math.min(maxv[i - 1][j - 1], maxv[i - 1][j]), maxv[i][j - 1]);
                max = Math.max(maxv[i][j], max);
            }
        }
        return max * max;
    }
}
