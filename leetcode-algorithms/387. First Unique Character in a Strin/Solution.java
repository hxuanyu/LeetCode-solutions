class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> cmap = new HashMap<>();

        for (char c : s.toCharArray()) cmap.put(c, cmap.getOrDefault(c, 0) + 1);

        for (int i = 0; i < s.length(); i++) {
        	if (cmap.get(s.charAt(i)) == 1) return i;
        }

        return -1;
    }
}
