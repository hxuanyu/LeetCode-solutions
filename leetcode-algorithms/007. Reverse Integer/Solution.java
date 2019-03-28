class Solution {
    public int reverse(int x) {
    	boolean bpositive = x > 0;
    	int val = reverse(x >= 0? (long)x : (long)-x);
    	return bpositive ? val : -val;
    }

    public int reverse(long x) {
        long rslt = 0;

        while (x > 0) {
        	rslt = 10 * rslt + x % 10;
        	x /= 10;
        	if (rslt > Integer.MAX_VALUE) return 0;

        }

        return (int) rslt;
    }
}
