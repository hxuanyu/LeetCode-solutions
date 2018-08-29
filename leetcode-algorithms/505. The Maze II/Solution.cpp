// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.
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
// Output: 12
// Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
//              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
// Output: -1
// Explanation: There is no way for the ball to stop at the destination.
//
// Note:
// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<vector<int>> que;
        que.push({start[0], start[1]});
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();

                int row = top[0];
                int col = top[1];
                int dis = distance[row][col];
                for (auto dir : dirs) {
                    int newrow = row + dir[0];
                    int newcol = col + dir[1];
                    int newdis = dis + 1;
                    if ((newrow < 0) || (newcol < 0) || (newrow >= maze.size()) || (newcol >= maze[0].size()) || (maze[newrow][newcol] == 1)) continue;
                    while ((newrow + dir[0] >= 0) && (newcol +dir[1] >= 0) && (newrow + dir[0] < maze.size()) && (newcol + dir[1] < maze[0].size()) && (maze[newrow + dir[0]][newcol + dir[1]] == 0)) {
                        newrow += dir[0];
                        newcol += dir[1];
                        newdis++;
                    }

                    if (newdis < distance[newrow][newcol]) {
                        que.push({newrow, newcol});
                        distance[newrow][newcol] = newdis;
                    }
                }
            }
        }

        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};
