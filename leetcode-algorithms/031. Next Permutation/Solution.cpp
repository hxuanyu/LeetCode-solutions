// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int i = nums.size() - 1;
        for (; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) break;
        }

        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int peak = i; // peak > 0, peak - 1 exists

        while ((i < nums.size()) && (nums[i] > nums[peak - 1])) i++;

        swap(nums[i - 1], nums[peak - 1]);

        sort(nums.begin() + peak, nums.end());
    }
};
