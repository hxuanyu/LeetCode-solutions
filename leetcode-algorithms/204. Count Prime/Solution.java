class Solution {
    public int countPrimes(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 0;
        else if (n == 2) return 0;
        else if (n == 3) return 1;
        else if (n == 4) return 2;

        boolean bprime[] = new boolean[n];

        for (int i = 0; i < bprime.length; i++) bprime[i] = true;
        bprime[0] = false;
        bprime[1] = false;
        bprime[2] = true;
        bprime[3] = true;

        for (int i = 2; i < Math.sqrt(n); i++) {
            for (int j = i * i; j < n; j += i) {
                bprime[j] = false;
            }
        }

        int count= 0;
        for (int i = 1; i < n; i++) {
            if (bprime[i]) count++;
        }

        return count;
    }
}
