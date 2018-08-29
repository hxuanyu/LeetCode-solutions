// You are given a m x n 2D grid initialized with these three possible values.
//
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
// Example:
//
// Given the 2D grid:
//
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
//
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = int(rooms.size());
        if (row == 0) return;
        int col = int(rooms[0].size());
        if (col == 0) return;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) {
                    visit(rooms, i, j);
                }
            }
        }
    }

    void visit(vector<vector<int>>& rooms, int i, int j) {

        vector<vector<int>> dirs = {{-1, 0},{0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> que;
        que.push(make_pair(i, j));
        int dis = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();

                for (auto dir : dirs) {
                    int newx = top.first + dir[0];
                    int newy = top.second + dir[1];
                    if ((newx < 0) || (newy < 0) || (newx >= rooms.size()) || (newy >= rooms[0].size()) || (rooms[newx][newy] == -1)) continue;
                    if (rooms[newx][newy] >= dis + 1) {
                        rooms[newx][newy] = dis + 1;
                        que.push(make_pair(newx, newy));
                    }
                }

            }
            dis++;
        }
    }
};
