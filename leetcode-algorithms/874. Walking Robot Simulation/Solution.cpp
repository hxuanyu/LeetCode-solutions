// A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:
//
// -2: turn left 90 degrees
// -1: turn right 90 degrees
// 1 <= x <= 9: move forward x units
// Some of the grid squares are obstacles.
//
// The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
//
// If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)
//
// Return the square of the maximum Euclidean distance that the robot will be from the origin.
//
//
//
// Example 1:
//
// Input: commands = [4,-1,3], obstacles = []
// Output: 25
// Explanation: robot will go to (3, 4)
// Example 2:
//
// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
// Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
//
//
// Note:
//
// 0 <= commands.length <= 10000
// 0 <= obstacles.length <= 10000
// -30000 <= obstacle[i][0] <= 30000
// -30000 <= obstacle[i][1] <= 30000
// The answer is guaranteed to be less than 2 ^ 31.
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        for (auto ob : obstacles) {
            obs.insert(make_pair(ob[0], ob[1]));
        }

        int result = INT_MIN;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curdir = 0;
        int x = 0;
        int y = 0;
        for (auto cmd : commands) {
            if (cmd == -2) {
                curdir = (curdir + 3) % 4;
            } else if (cmd == -1) {
                curdir = (curdir + 1) % 4;
            } else {
                for (int i = 0; i < cmd; i++) {
                    if (obs.count(make_pair(x + dirs[curdir][0], y + dirs[curdir][1])) == 0) {
                        x += dirs[curdir][0];
                        y += dirs[curdir][1];
                    } else break;
                }
            }
            result = max(result, x * x + y * y);
        }

        return result;
    }
};
