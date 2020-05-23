class Solution56 {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return intervals;
        
	Arrays.sort(intervals, (a1, a2) -> a1[0] - a2[0]);

        List<int[]> rslt = new ArrayList<>();
        rslt.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int[] next = intervals[i];

            int curend = rslt.get(rslt.size() - 1)[1];
            int newstart = next[0];
            int newend = next[1];

            if (newstart > curend) {
                rslt.add(next);
            } else {
                if (newend > curend) {
                    rslt.get(rslt.size() - 1)[1] = newend;
                }
            }
        }

        int[][] rr = new int[rslt.size()][2];
        for (int i = 0; i < rslt.size(); i++) {
            rr[i] = rslt.get(i);
        }

        return rr;
    }
}
