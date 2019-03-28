class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        if (row == 0) return false;

        int col = matrix[0].length;
        if (col == 0) return false;

        int i = 0;
        int j = col - 1;

        do {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        } while ((i < row) && (j >= 0));

        return false;
    }
}
