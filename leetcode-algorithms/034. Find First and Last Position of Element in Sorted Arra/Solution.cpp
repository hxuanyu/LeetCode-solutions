// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findstart(nums, 0, nums.size() - 1, target);
        int end = findend(nums, 0, nums.size() - 1, target);
        vector<int> rslt = {start, end};
        return rslt;
    }

    int findstart(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            if (nums[start] == target) {
                return start;
            } else if ((target < nums[start]) || (target > nums[end])) {
                return -1;
            }

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                if (mid == start) return start;
                else if (nums[mid - 1] != target) return mid;
                else end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    int findend(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            if (nums[end] == target) {
                return end;
            } else if ((target < nums[start]) || (target > nums[end])) {
                return -1;
            }

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                if (mid == end) return end;
                else if (nums[mid + 1] != target) return mid;
                else start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};
