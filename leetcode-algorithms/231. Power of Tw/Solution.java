class Solution {
    public boolean isPowerOfTwo(int n) {
       if (n <= 0) return false;

       int count = 0;
       while (n > 0) {
           count++;
           n = n & (n - 1);
       }
       return count == 1;
    }
}
