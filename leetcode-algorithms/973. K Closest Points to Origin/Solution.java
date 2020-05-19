class Solution {
    public int[][] kClosest(int[][] points, int K) {
        PriorityQueue<int[]> que = new PriorityQueue<>((a2, a1) -> a1[0] * a1[0] + a1[1] * a1[1] - a2[0] * a2[0] - a2[1] * a2[1]);

        for (int[] point : points) {
            que.add(point);
            if (que.size() > K) {
                que.poll();
            }
        }

        int[][] rslt = new int[K][];

        for (int i = 0; i < K; i++) {
            rslt[i] = que.poll();
        }

        return rslt;
    }
}
