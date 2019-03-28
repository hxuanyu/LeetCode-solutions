class Solution {
    public String countAndSay(int n) {
        if (n == 1) return "1";
        else if (n == 2) return "11";

        String s = "11";
        StringBuilder news = new StringBuilder();
        StringBuilder local = new StringBuilder();
        n -= 2;
        char lastc = s.charAt(0);
        int count = 0;

        while (n-- > 0) {

            int i = 0;
            lastc = s.charAt(0);
            count = 0;

            while (i < s.length()) {
                if (s.charAt(i) == lastc) {
                    count++;
                } else {
                    local.setLength(0);
                    local.append(count);
                    local.append(lastc);

                    news.append(local);

                    lastc = s.charAt(i);
                    count = 1;
                }

                i++;
            }

            local.setLength(0);
            local.append(count);
            local.append(lastc);
            news.append(local);

            s = news.toString();
            news.setLength(0);
        }


        return s;
    }
}
