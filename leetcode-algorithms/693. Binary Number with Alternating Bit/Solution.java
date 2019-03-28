class Solution {
    public boolean hasAlternatingBits(int n) {

    	int last = -1;
        while (n > 0) {
        	int current = n % 2;
        	n = n / 2;
        	if (last != -1) {
        		if (last == current) return false;
        	}

        	last = current;
        }

        return true;
    }
}
