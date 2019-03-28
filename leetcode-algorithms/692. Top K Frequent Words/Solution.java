class itemaa {
	public itemaa(String str, int count) {
		this.str = str;
		this.count = count;
	}

	public String str;
	public int count;
}
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> vmap = new HashMap<>();
        for (String word : words) {
        	vmap.put(word, vmap.getOrDefault(word, 0) + 1);
        }

        List<itemaa> va =   vmap.keySet().stream().map(key -> new itemaa(key, vmap.get(key))).collect(Collectors.toList());

        PriorityQueue<itemaa> que = new PriorityQueue<>((a, b) -> {
        	if (a.count != b.count) return a.count - b.count;
        	else return b.str.compareTo(a.str);
        });

        for (itemaa item : va) {
        	if (que.size() < k) que.add(item);
        	else if (((que.peek().count == item.count) && (item.str.compareTo(que.peek().str) < 0)) || (que.peek().count < item.count)) {
        		que.poll();
        		que.add(item);
        	}
        }

        List<String> rslt = new ArrayList<>();
        while (!que.isEmpty()) {
        	rslt.add(0, que.poll().str);
        }

        return rslt;
    }
}
