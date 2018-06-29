class Solution {
    class dir {
        public dir(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int x;
        public int y;
    }

    public int[][] imageSmoother(int[][] M) {
        dir[] dirs = {new dir(-1, 0),
                new dir(-1, 1),
                new dir(0, 1),
                new dir(1, 1),
                new dir(1, 0),
                new dir(1, -1),
                new dir(0, -1),
                new dir(-1, -1)};

        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[i].length; j++) {
                int val = M[i][j] & 0x00ff;
                int count = 1;
                for (dir d : dirs) {
                    int newx = i + d.x;
                    int newy = j + d.y;
                    if ((newx < 0) || (newx >= M.length) || (newy < 0) || (newy >= M[0].length)) continue;
                    val += M[newx][newy] & 0x00ff;
                    count++;
                }

                val = val / count;
                M[i][j] = val << 8 | M[i][j];
            }
        }

        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[0].length; j++) {
                M[i][j] = (M[i][j] & 0xff00) >> 8;
            }
        }

        return M;
    }
}
