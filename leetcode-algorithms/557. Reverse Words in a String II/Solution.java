class Solution {
    public String reverseWords(String s) {
        String [] parts = s.split(" ");

        StringBuilder finalsb = new StringBuilder();
        for (String str : parts) {
        	StringBuilder sb = new StringBuilder(str);
        	sb.reverse();
        	finalsb.append(sb.toString());
        	finalsb.append(" ");
        }

        String rslt = finalsb.toString();
        return rslt.substring(0, rslt.length() - 1);
    }
}
