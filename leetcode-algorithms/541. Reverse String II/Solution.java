// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

class Solution {
    public String reverseStr(String s, int k) {
        int endpos = s.length() - 1;
        int pos = 0;

        StringBuffer sb = new StringBuffer(s);

        while (pos <= endpos) {
            int lenleft = endpos - pos + 1;
            if (lenleft >= 2 * k) {
                reverse(sb, pos, pos + k - 1);
                pos = pos + 2 * k;
            } else if (lenleft >= k) {
                reverse(sb, pos, pos + k - 1);
                break;
            } else {
                reverse(sb, pos, endpos);
                break;
            }
        }

        return sb.toString();
    }

    public void reverse(StringBuffer sb, int start, int end) {
        while (start < end) {
            char temp = sb.charAt(start);
            sb.setCharAt(start, sb.charAt(end));
            sb.setCharAt(end, temp);
            start++;
            end--;
        }
    }
}
