// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
// Example 2:
//
// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> rslt;

        int pos = 0;
        int size = nums.size();
        while (pos < size) {
            int p = pos;
            int i = 0;
            while ((p + i < size) && (nums[p + i] == nums[p] + i)) {
                i++;
            }

            char str[100];
            if (i == 1) sprintf(str, "%d", nums[p]);
            else sprintf(str, "%d->%d", nums[p], nums[p + i - 1]);
            rslt.push_back(str);
            pos = p + i;
        }
        return rslt;
    }
};
