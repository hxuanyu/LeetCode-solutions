class Solution {
	class point1 {
		int x;
		int y;
		public point1(int x, int y) { this.x = x; this.y = y; }
	}

    public int numberOfBoomerangs(int[][] points) {
    	int rslt = 0;
        for (int i = 0; i < points.length; i++) {
        	Map<Integer, List<point1>> cmap = new HashMap<>();
        	for (int j = 0; j < points.length; j++) {
        		if (i == j) continue;
        		point1 local = new point1(points[i][0], points[i][1]);
        		point1 po = new point1(points[j][0], points[j][1]);
        		int dis = cal(local, po);

        		List<point1> list = cmap.getOrDefault(dis, new ArrayList<point1>());
        		list.add(po);
        		cmap.put(dis, list);
        	}

        	for (Map.Entry<Integer, List<point1>> entry : cmap.entrySet()) {
        		if (entry.getValue().size() <= 1) continue;

        		int size = entry.getValue().size();
        		rslt += size * (size - 1);
        	}
        }

        return rslt;
    }

    int cal(point1 a, point1 b) {
    	return (a.x - b.x) *(a.x - b.x) +(a.y - b.y) *(a.y - b.y);
    }
}
