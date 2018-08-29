// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
// Input: [3,4,5,1,2]
// Output: 1
// Example 2:
//
// Input: [4,5,6,7,0,1,2]
// Output: 0
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findmin(nums, 0, int(nums.size() - 1));
    }

    int findmin(vector<int>& nums, int a, int b) {
        if (a == b) return nums[a];
        else if (a + 1 == b) return min(nums[a], nums[b]);
        if (nums[a] < nums[b]) return nums[a]; // normal sorted
        else { // rotated
            int mid = a + (b - a) / 2;
            if (nums[a] < nums[mid]) return findmin(nums, mid, b);
            else return findmin(nums, a, mid);
        }
    }
};
