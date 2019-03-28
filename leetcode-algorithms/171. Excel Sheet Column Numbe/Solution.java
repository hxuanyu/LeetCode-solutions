class Solution {
    public int titleToNumber(String s) {
        Map<Character, Integer> cmap = new HashMap<>();
        for (char c = 'A'; c <= 'Z'; c++) {
            cmap.put(c, c - 'A' + 1);
        }

        int rslt = 0;
        for (char c : s.toCharArray()) {
            rslt = rslt * 26 + cmap.get(c);
        }

        return rslt;
    }
}
