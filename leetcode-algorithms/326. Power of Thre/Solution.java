class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false;
        int v = 3;
        while (v < Integer.MAX_VALUE / 3) v = v* 3;
        System.out.println(v);

        return v % n == 0;
    }
}
