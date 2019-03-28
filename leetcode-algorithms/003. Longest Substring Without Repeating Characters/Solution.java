class Solution {
    public int lengthOfLongestSubstring(String s) {
    	if (s.length() <= 1) return s.length();
        Set<Character> set = new HashSet<>();

        int i = 0;
        int begin = 0;
        int maxlen = 0;
        while (i < s.length()) {
        	char c = s.charAt(i);

        	while (set.contains(c)) {
        		set.remove(s.charAt(begin++));
        	}

        	set.add(c);
        	maxlen = Math.max(i - begin + 1, maxlen);
        	i++;
        }

        return maxlen;
    }
}
