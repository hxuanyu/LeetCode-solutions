class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> temp = new ArrayList<>();
        impl(s, 0, temp);

        List<String> f = new ArrayList<>();
        for (List<String> li : rslt) {
            String t = "";
            for (String str: li) {
                t += str;
                t += ".";
            }

            f.add(t.substring(0, t.length() - 1));
        }

        return f;
    }

    void impl(String s, int pos, List<String> temp) {
        if ((temp.size() == 4) && (pos != s.length())) return;

        if ((pos == s.length()) && (temp.size() == 4)) {
            List<String> t = new ArrayList<>(temp);
            rslt.add(t);
            return;
        } else if (pos >= s.length()) return;

        if (s.charAt(pos) == '0') {
            temp.add("0");
            impl(s, pos + 1, temp);
            temp.remove(temp.size() - 1);
        } else {
            for (int i = pos; i < Math.min(pos + 3, s.length()); i++) {
                String sub = s.substring(pos, i + 1);
                if (Integer.valueOf(sub) <= 255) {
                    temp.add(sub);

                    impl(s, i + 1, temp);
                    temp.remove(temp.size() - 1);
                }
            }
        }
    }

    List<List<String>> rslt = new ArrayList<>();
}
