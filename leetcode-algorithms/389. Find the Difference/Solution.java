class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> vmap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
        	vmap.put(s.charAt(i), vmap.getOrDefault(s.charAt(i), 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
        	char c = t.charAt(i);

        	if (vmap.containsKey(c) == false) return c;

        	if (vmap.get(c) > 1) vmap.put(c, vmap.get(c) - 1);
        	else vmap.remove(c);
        }
        return ' ';
    }
}
