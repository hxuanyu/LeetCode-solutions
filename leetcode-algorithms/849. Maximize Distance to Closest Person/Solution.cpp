// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.
//
// There is at least one empty seat, and at least one person sitting.
//
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
//
// Return that maximum distance to closest person.
//
// Example 1:
//
// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation:
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
// Example 2:
//
// Input: [1,0,0,0]
// Output: 3
// Explanation:
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
// Note:
//
// 1 <= seats.length <= 20000
// seats contains only 0s or 1s, at least one 0, and at least one 1.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        vector<int> leftv(size, -1);

        int left = -1;
        for (int i = 0; i < size; i++) {
            if (seats[i] == 0) {
                leftv[i] = left;
            } else left = i;
        }

        vector<int> rightv(size, -1);
        int right = -1;
        for (int i = size - 1; i >= 0; i--) {
            if (seats[i] == 0) {
                rightv[i] = right;
            } else right = i;
        }

        int maxdis = 0;
        int pos = 0;
        int localdis = 0;
        for (int i = 0; i < size; i++) {
            if (seats[i] == 0) {
                if ((leftv[i] != -1) && (rightv[i] != -1)) {
                    localdis = min(i - leftv[i], rightv[i] - i);
                } else if (leftv[i] != -1) {
                    localdis = i - leftv[i];
                } else if (rightv[i] != -1) {
                    localdis = rightv[i] - i;
                }
                if (localdis > maxdis) {
                    maxdis = localdis;
                    pos = i;
                }
            }
        }

        return maxdis;
    }
};
