class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> smap = new HashMap<>();
        for (char c : s.toCharArray()) {
            smap.put(c, smap.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            if (!smap.containsKey(c)) return false;
            smap.put(c, smap.get(c) - 1);
            if (smap.get(c) == 0) smap.remove(c);
        }
        
        return smap.isEmpty();
    }
}
