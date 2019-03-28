class Solution {
    public int trap(int[] height) {
        if (height.length <= 2) return 0;
        int [] lefts = new int[height.length];
        lefts[0] = 0;
        for (int i = 1; i < lefts.length; i++) {
        	lefts[i] = Math.max(height[i - 1], lefts[i - 1]);
        }

        int[] rights = new int[height.length];
        rights[rights.length - 1] = 0;
        for (int i = rights.length - 2; i >= 0; i--) {
        	rights[i] = Math.max(height[i + 1], rights[i + 1]);
        }

        int total = 0;
        for (int i = 0; i < height.length; i++) {
        	int top = Math.min(lefts[i], rights[i]);
        	total += Math.max(top - height[i], 0);
        }

        return total;
    }
}
