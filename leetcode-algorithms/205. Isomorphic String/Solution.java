class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;

        Map<Character, Character> vmap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);

            if (!vmap.containsKey(tc)) {
                vmap.put(tc, sc);
            } else {
                if (vmap.get(tc) != sc) return false;
            }
        }
        System.out.println("here");
        List<Character> values = new ArrayList<>(vmap.values());

        Set<Character> set = new HashSet<>(values);

        return values.size() == set.size();
    }
}
