class Solution {
    public String longestPalindrome(String S) {
        int maxlen = 0;
        int pos = 0;

        for (int i = 0; i < S.length(); i++) {
        	int len = 1;
        	int left = i;

        	while ((left - 1 >= 0) && (S.charAt(i) == S.charAt(left - 1))) {
        		left--;
        		len++;
        	}
        	int right = i;
        	while ((right + 1 < S.length()) && (S.charAt(right + 1) == S.charAt(i))) {
        		right++;
        		len++;
        	}

        	while ((left - 1 >= 0) && (right + 1 < S.length()) && (S.charAt(left - 1) == S.charAt(right + 1))) {
        		len += 2;
                left--;
        		right++;
        	}

        	if (len > maxlen) {
        		maxlen = len;
        		pos = left;
        	}
        }

        return S.substring(pos, maxlen + pos);
    }
}
