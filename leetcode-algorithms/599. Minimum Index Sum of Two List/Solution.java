class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
    	List<String> common = new ArrayList<>(Arrays.asList(list1));
    	List<String> l2 = Arrays.asList(list2);
    	common.retainAll(l2);

    	Map<String, Integer> vmap1 = new HashMap<>();
    	for (int i = 0; i < list1.length; i++) vmap1.put(list1[i], i);

    	Map<String, Integer> vmap2 = new HashMap<>();
    	for (int i = 0; i < list2.length; i++) vmap2.put(list2[i], i);
    	
    	int minidx = Integer.MAX_VALUE;
    	List<String> rslt = new ArrayList<>();
    	for (String co : common) {
    		if (vmap1.get(co) + vmap2.get(co) < minidx) {
    			minidx = vmap1.get(co) + vmap2.get(co);
    			rslt.clear();
    			rslt.add(co);
    		} else if (vmap1.get(co) + vmap2.get(co) == minidx) {
    			rslt.add(co);
    		}
    	}

    	String [] rslt1 = new String[rslt.size()];
    	rslt.toArray(rslt1);
    	return rslt1;
    }
}
