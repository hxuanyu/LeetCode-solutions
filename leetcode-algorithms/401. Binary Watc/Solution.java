class Solution {
	int [] vals = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
	List<Integer> vhour = new ArrayList<>();
	List<Integer> vmin = new ArrayList<>();
	List<String> rslt = new ArrayList<>();
    public List<String> readBinaryWatch(int num) {
        perm(0, num);
        return rslt;
    }

    void perm(int pos, int total) {
    	if (vhour.size() + vmin.size() == total) {
    		int h = 0;
    		for (int i : vhour) h += i;
    		if (h >= 12) return;
    		int m = 0;
    		for (int i : vmin) m += i;
    		if (m >= 60) return;
    		String temp = String.format("%d:%s", h, m <= 9 ? "0" + String.valueOf(m): String.valueOf(m));
    		rslt.add(temp);
    	} else if (vhour.size() + vmin.size() > total) return;

    	for (int i = pos; i < vals.length; i++) {
	    	if (i <= 3) {
	    		vhour.add(vals[i]);
	    		perm(i + 1, total);
	    		vhour.remove(vhour.size() - 1);
	    	} else {
	    		vmin.add(vals[i - 4]);
	    		perm(i + 1, total);
	    		vmin.remove(vmin.size() - 1);
	    	}
    	}
    }
}
