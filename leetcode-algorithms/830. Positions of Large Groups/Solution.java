class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> rslt = new ArrayList<List<Integer>>();
        int start = 0;
        while (start < S.length()) {
            int end = start;
            char c = S.charAt(start);

            while ((end < S.length()) && (S.charAt(end) == c)) end++;
            int len = end - start;
            if (len >= 3) {
                rslt.add(new ArrayList<Integer>(Arrays.asList(start, end - 1)));
            }
            start = end;
        }

        return rslt;
    }
}
