class Solution {
    public int repeatedStringMatch(String A, String B) {
    	String temp = A;
    	int times = 1;
        do {
        	if ((temp).lastIndexOf(B) != -1) return times;
        	times++;
        	temp+= A;
        } while (temp.length() - 2 * A.length() <= B.length());

        return -1;
    }
}
