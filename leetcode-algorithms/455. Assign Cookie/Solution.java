class Solution {
    public int findContentChildren(int[] g, int[] s) {
    	if ((g.length == 0) || (s.length == 0)) return 0;
        Arrays.sort(g);
        Arrays.sort(s);

        int count = 0;
        int j = s.length - 1;
        for (int i = g.length - 1; i>= 0; i--) {
        	if (g[i] > s[j]) continue;

        	if (j >= 0) count++;
        	j--;
        	if (j < 0) break;
        }

        return count;
    }
}
