class Solution {
    public boolean validPalindrome(String s) {
        if (s.length() <= 2) return true;

        int left = 0;
        int right = s.length() - 1;
        boolean difffound = false;
        while (left < right) {
        	if (s.charAt(left) == s.charAt(right)) {
            	left++;
            	right--;
        		continue;
        	} else {
        		difffound = true;
        		break;
        	}
        }

        return difffound ? realp(s.substring(left, right)) || realp(s.substring(left + 1, right + 1)) : true;
    }

    private boolean realp(String s) {
    	int i = 0;
    	int j = s.length() - 1;
    	while (i < j) {
    		if (s.charAt(i++) != s.charAt(j--)) return false;
    	}

    	return true;
    }
}
