class Solution {
    public int calPoints(String[] ops) {
    	Stack<Integer> sta = new Stack<>();
        for (String v : ops) {
        	if (v.equals("+")) {
        		if (sta.size() >= 2) {
        			int last = sta.pop();
        			int secondlast = sta.pop();
        			sta.push(secondlast);
        			sta.push(last);
        			sta.push(last + secondlast);
        		}
        	} else if (v.equals("D")) {
        		if (!sta.isEmpty()) {
        			sta.push(sta.peek() * 2);
        		}
        	} else if (v.equals("C")) {
        		if (!sta.isEmpty()) {
        			sta.pop();
        		}
        	} else {
        		sta.push(Integer.valueOf(v));
        	}
        }

        int total = 0;
        while (!sta.isEmpty()) total += sta.pop();

        return total;
    }
}
