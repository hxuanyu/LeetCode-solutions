class Solution {
    public boolean isPalindrome(String s) {
        s = s.toUpperCase();

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            int pl = left;
            while ((pl < s.length()) && !isvalid(s.charAt(pl))) pl++;

            int pr = right;
            while ((pr >= 0) && !isvalid(s.charAt(pr))) pr--;

            if (pl >= pr) break;
            if (s.charAt(pl) != s.charAt(pr)) return false;

            left = pl + 1;
            right = pr - 1;
        }

        return true;
    }

    private boolean isvalid(char c) {
        return ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (('0' <= c) && (c <= '9')));
    }
}
