class Solution {
    public int fib(int N) {
    	if (N == 0) return 0;
    	else if (N == 1) return 1;
        int [] rslt = new int[N + 1];
        rslt[0] = 0;
        rslt[1] = 1;

        for (int i = 2; i <= N; i++) {
        	rslt[i] = rslt[i - 1] + rslt[i - 2];
        }

        return rslt[N];
    }
}
