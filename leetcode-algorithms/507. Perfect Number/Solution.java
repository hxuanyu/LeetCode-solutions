class Solution {
    public boolean checkPerfectNumber(int num) {
    	if (num <= 0) return false;

    	int total = 0;
    	int sqrt = (int)Math.sqrt(num);
    	for (int i = 1; i <= sqrt; i++) {
    		if (i == 1) total += 1;
    		else if (num % i == 0) {
    			total += i;
    			total += num / i;
    		}
    	}

    	if (sqrt * sqrt == num) total -= sqrt;
    	return total == num;
    }
}
