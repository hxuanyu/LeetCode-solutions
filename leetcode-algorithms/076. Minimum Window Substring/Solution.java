class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";
        Map<Character, Integer> fmap = new HashMap<>();
        for (char c : t.toCharArray()) {
            fmap.put(c, fmap.getOrDefault(c, 0) + 1);
        }

        int i = 0;
        int count = 0;

        int minlen = Integer.MAX_VALUE;
        int pos = 0;
        int start = 0;

        while (i < s.length()) {
            char c = s.charAt(i);

            if (fmap.containsKey(c)) {
                fmap.put(c, fmap.get(c) - 1);
                if (fmap.get(c) >= 0) count++;
            }

            while (count == t.length()) {
                int local = i - start + 1;
                if (local < minlen) {
                    minlen = local;
                    pos = start;
                }

                //start++;
                char v = s.charAt(start++);
                if (fmap.containsKey(v)) {
                    fmap.put(v, fmap.get(v) + 1);
                    if (fmap.get(v) > 0) count--;
                }
            }
            i++;
        }

        return minlen == Integer.MAX_VALUE ? "" : s.substring(pos, pos + minlen);
    }
}
