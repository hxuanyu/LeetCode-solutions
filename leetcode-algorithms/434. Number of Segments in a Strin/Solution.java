class Solution {
    public int countSegments(String s) {

    	int i = 0;
    	int count = 0;
    	while (i < s.length()) {
    		while ((i < s.length()) && (s.charAt(i) == ' ')) i++;
    		if (i == s.length()) break;

    		while ((i < s.length()) && (s.charAt(i) != ' ')) i++;
    		count++;
    	}

    	return count;
    }
}
