class Solution {
        public int addDigits(int num) {
        while (num >= 10) {
            String str = String.valueOf(num);
            int t = 0;
            for (int i = 0; i < str.length(); i++) {
                t += str.charAt(i) - '0';
            }
            num = t;
        }

        return num;
    }
}
