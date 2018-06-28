class Solution {
    public int findComplement(int num) {
        int rslt = 0;
        int pos = 1;
        
        while (num > 0) {
            int rem = num % 2;
            rem ^= 1;
            rslt += pos * rem;
            pos *= 2;
            num /= 2;
        }

        return rslt;
    }
}
