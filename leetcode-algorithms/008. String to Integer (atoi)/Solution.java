class Solution {
    public int myAtoi(String str) {
        if ((str == null) || (str.length() == 0)) return 0;
        int pos = 0;
        long num = 0;
        while ((pos < str.length()) && (str.charAt(pos) == ' ')) pos++;
        if (pos == str.length()) return (int)num;

        boolean bPositive = true;

        if (str.charAt(pos) == '+') pos++;
        else if (str.charAt(pos) == '-') {
            pos++;
            bPositive = false;
        }

        while ((pos < str.length()) && (Character.isDigit(str.charAt(pos)))) {
            num = 10 * num + Character.getNumericValue(str.charAt(pos));
            if ((bPositive) && (num > Integer.MAX_VALUE)) return Integer.MAX_VALUE;
            else if ((!bPositive) && (num - 1 > Integer.MAX_VALUE)) return Integer.MIN_VALUE;
            pos++;
        }

        return (int)(bPositive ? num : -num);

    }
}
