class Solution {
    public List<String> letterCasePermutation(String S) {
        StringBuffer temp = new StringBuffer();
        List<String> rslt = new ArrayList<>();

        perm(S, 0, temp, rslt);
        return rslt;
    }

    public void perm(String S, int pos, StringBuffer s, List<String> rslt) {
        if ((pos == S.length()) && (s.length() == S.length())) {
            rslt.add(s.toString());
            return;
        }

        Character c = S.charAt(pos);
        ArrayList<Character> vec = new ArrayList<>();
        if (Character.isAlphabetic(c)) {
            vec.add(c);
            if (Character.isLowerCase(c)) vec.add(Character.toUpperCase(c));
            else vec.add(Character.toLowerCase(c));
        } else vec.add(c);

        for (Character c1: vec) {
            s.append(c1);
            perm(S, pos + 1, s, rslt);
            s.deleteCharAt(s.length() - 1);
        }
    }
}
