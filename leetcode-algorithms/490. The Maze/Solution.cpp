// here is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
//
// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
//
// Example 1
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)
//
// Output: true
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
//
// Example 2
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)
//
// Output: false
// Explanation: There is no way for the ball to stop at the destination.
//
// Note:
// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> que;
        que.push(make_pair(start[0], start[1]));
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();

                if ((top.first == destination[0]) && (top.second == destination[1])) return true;

                int row = top.first;
                int col = top.second;
                for (auto dir : dirs) {
                    int newrow = row + dir[0];
                    int newcol = col + dir[1];
                    if ((newrow < 0) || (newcol < 0) || (newrow >= maze.size()) || (newcol >= maze[0].size()) || (maze[newrow][newcol] == 1)) continue;
                    while ((newrow + dir[0] >= 0) && (newcol +dir[1] >= 0) && (newrow + dir[0] < maze.size()) && (newcol + dir[1] < maze[0].size()) && (maze[newrow + dir[0]][newcol + dir[1]] == 0)) {
                        newrow += dir[0];
                        newcol += dir[1];
                    }

                    if (visited[newrow][newcol]) continue;
                    que.push(make_pair(newrow, newcol));
                    visited[newrow][newcol] = true;
                }
            }
        }

        return false;
    }
};
