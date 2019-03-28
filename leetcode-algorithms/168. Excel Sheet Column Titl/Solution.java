class Solution {
    public String convertToTitle(int n) {
        char a[] = new char[26];
        for (int i = 0; i < 26; i++) a[i] = (char)('A' + i);

        String rslt = "";
        while (n > 0) {
            rslt = a[(n - 1) % 26] + rslt;
            n = (n - 1) / 26;
        }

        return rslt;
    }
}
