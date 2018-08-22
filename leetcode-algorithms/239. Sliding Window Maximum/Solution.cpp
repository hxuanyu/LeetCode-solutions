// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Example:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Note:
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
// Follow up:
// Could you solve it in linear time?
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rslt;
        if (nums.empty()) return rslt;
        deque<int> que;
        for (int i = 0; i < k; i++) {
            int v = nums[i];
            if (que.empty()) que.push_back(v);
            else {
                int count = 0;
                while ((!que.empty()) && (que.back() < v)) {
                    que.pop_back();
                    count++;
                }

                for (int i = 0; i < count; i++) que.push_back(v);
                que.push_back(v);
            }
        }


        int pos = k;
        do {
            rslt.push_back(que.front());
            que.pop_front();

            if (pos == nums.size()) break;

            int count = 0;
            int newv = nums[pos];
            while ((!que.empty()) && (que.back() < newv)) {
                que.pop_back();
                count++;
            }

            for (int i = 0; i < count; i++) que.push_back(newv);
            que.push_back(newv);
            pos++;
        } while (true);

        return rslt;
    }
};
