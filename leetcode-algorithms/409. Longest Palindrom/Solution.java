class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> vmap = new HashMap<>();

        for (char c : s.toCharArray()) {
        	int count = vmap.getOrDefault(c, 0);
        	count++;
        	vmap.put(c, count);
        }

        int count = 0;
        boolean foundodd = false;
        for (Map.Entry<Character, Integer> entry : vmap.entrySet()) {
        	if (entry.getValue() % 2 == 0) count += entry.getValue();
        	else {
        		count += (entry.getValue() - 1);
        		foundodd = true;
        	}
        }

        return foundodd ? count + 1 : count;
    }
}
