class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums == null) return nums;
        if (r * c != nums.length * nums[0].length) return nums;

        int [][] rslt = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                rslt[i][j] = nums[(i * c + j) / nums[0].length][(i * c + j) % nums[0].length];
            }
        }

        return rslt;
    }
}
