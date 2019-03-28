class Solution {
    public String convertToBase7(int num) {
    	if (num < 0) {
    		if (num == Integer.MIN_VALUE) {
    			long val = Integer.MAX_VALUE + 1;
    			return "-" + convertToBase7impl(val);
    		}
    		return "-" + convertToBase7(-num);
    	} else if (num == 0) return "0";

    	return convertToBase7impl(num);
    }

    String convertToBase7impl(long num) {
    	StringBuilder sb = new StringBuilder();

    	while (num > 0) {
    		sb.insert(0, String.valueOf(num % 7));
    		num /= 7;
    	}

    	return sb.toString();
    }
}
