class Solution {
    public int numJewelsInStones(String J, String S) {
        TreeSet<Character> cset = new TreeSet<>();

        for (int i = 0; i < J.length(); i++) {
            cset.add(J.charAt(i));
        }

        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (cset.contains(S.charAt(i))) count++;
        }

        return count;
    }
}
