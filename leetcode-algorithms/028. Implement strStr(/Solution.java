class Solution {
    public int strStr(String haystack, String needle) {
        if ((needle == null) || (needle.isEmpty()))return 0;

        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        	if (valid(haystack, needle, i)) return i;
        }

        return -1;
    }

    boolean valid(String haystack, String needle, int idx) {
    	for (int i = 0; i < needle.length(); i++) {
    		if (needle.charAt(i) != haystack.charAt(i + idx)) return false;
    	}

    	return true;
    }
}
