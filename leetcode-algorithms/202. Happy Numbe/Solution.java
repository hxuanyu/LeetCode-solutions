class Solution {
    Set<Integer> vset = new HashSet<Integer>();
    public boolean isHappy(int n) {
        if (n == 1) return true;
        if (vset.contains(n)) return false;

        vset.add(n);
        String str = String.valueOf(n);
        int v = 0;
        for (int i = 0; i < str.length(); i++) {
            v += (str.charAt(i) - '0') * (str.charAt(i) - '0');
        }

        return isHappy(v);
    }
}
