// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> highleft(height.size());
        vector<int> highright(height.size());

        int left = 0;
        while ((left < height.size()) && (height[left] == 0)) left++;
        int right = height.size() - 1;;
        while ((right >= 0) && (height[right] == 0)) right--;

        if (left >= right) return 0;

        highleft[left] = height[left];
        for (int i = left + 1; i <= right; i++) {
            highleft[i] = max(highleft[i - 1], height[i - 1]);
        }

        highright[right] = height[right];
        for (int i = right - 1; i >= left; i--) {
            highright[i] = max(highright[i + 1], height[i + 1]);
        }

        int total = 0;
        for (int i = left + 1; i < right; i++) {
            int minhi = min(highleft[i], highright[i]);
            total += (minhi > height[i] ? minhi - height[i] : 0);
        }

        return total;
    }
};
