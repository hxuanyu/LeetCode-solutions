// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
// For the left two athletes, you just need to output their relative ranks according to their scores.
// Note:
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> value_to_pos;
        priority_queue<int> que;

        for (int i = 0; i < nums.size(); i++) {
            value_to_pos[nums[i]] = i;
            que.push(nums[i]);
        }

        vector<string> rslt(nums.size());

        int i = 0;
        while (!que.empty()) {
            auto top = que.top();
            if (i == 0) rslt[value_to_pos[top]] = "Gold Medal";
            else if (i == 1) rslt[value_to_pos[top]] = "Silver Medal";
            else if (i == 2) rslt[value_to_pos[top]] = "Bronze Medal";
            else rslt[value_to_pos[top]] = std::to_string(i+1);
            i++;
            que.pop();
        }

        return rslt;
    }
};
