class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        return find(s, 0, wordDict);
    }

    boolean find(String s, int pos, List<String> wordDict) {
        if (pos == s.length()) return true;
        if (vmap.containsKey(s.substring(pos))) return vmap.get(s.substring(pos));

        for (int i = pos; i < s.length(); i++) {
            String sub = s.substring(pos, i + 1);
            boolean found = wordDict.contains(sub) && find(s, i + 1, wordDict);
            if (found) return true;
        }

        vmap.put(s.substring(pos), false);
        return false;
    }

    Map<String, Boolean> vmap = new HashMap<>();
}
