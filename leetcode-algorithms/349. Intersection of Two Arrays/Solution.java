// Given two arrays, write a function to compute their intersection.
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
// Note:
// Each element in the result must be unique.

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set1 = new HashSet<Integer>();
        for (int v : nums1) set1.add(v);

        HashSet<Integer> set2 = new HashSet<Integer>();
        for (int v : nums2) set2.add(v);

        set1.retainAll(set2);

        int [] rr = new int[set1.size()];
        int i = 0;
        for (Integer v : set1) {
            rr[i++] = v;
        }

        return rr;
    }
}
