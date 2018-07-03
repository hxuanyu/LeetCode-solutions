class Solution {
    public String reverseVowels(String s) {
        HashSet<Character> set = new HashSet<Character>(Arrays.asList('a','e','i','o','u','A','E','I','O','U'));

        StringBuffer sb = new StringBuffer(s);
        int a = 0;
        int b = s.length() - 1;
        while (a < b) {
            while ((a < s.length()) && !set.contains(s.charAt(a))) a++;
            while ((b >= 0) && !set.contains(s.charAt(b))) b--;
            if (a >= b) break;

            char temp = sb.charAt(a);
            sb.setCharAt(a, sb.charAt(b));
            sb.setCharAt(b, temp);
            a++;
            b--;
        }

        return sb.toString();
    }
}
