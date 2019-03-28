class Solution {
    public int countBinarySubstrings(String s) {
    	int total = 0;
        for (int i = 0; i < s.length() - 1; i++) {
        	if (s.charAt(i) == s.charAt(i + 1)) continue;
        	total += countpos(s, i);
        }

        return total;
    }

    private int countpos(String s, int i) {
    	int left = i;
    	int right = i + 1;
    	int total = 1;
    	while ((left - 1 >= 0) && (right + 1 < s.length())) {
    		if ((s.charAt(left - 1) == s.charAt(left))  && (s.charAt(right) == s.charAt(right + 1))) {
    			left--;
    			right++;
    			total++;
    		} else break;
    	}

    	return total;
    }
}
