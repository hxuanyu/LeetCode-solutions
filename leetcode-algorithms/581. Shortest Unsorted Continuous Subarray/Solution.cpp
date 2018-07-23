// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.
class item {
public:
    int val;
    int pos;
    item(int val, int pos) { this->val = val; this->pos = pos; }
};

class cmp {
public:
    bool operator()(item& a, item& b) {
        return a.val < b.val;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        int left = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sorted[i]) {
                left = i;
                break;
            }
        }

        if (left == -1) return 0;

        int right = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != sorted[i]) {
                right = i;
                break;
            }
        }

        if (right == -1) return 0;

        return right - left + 1;
    }
};
