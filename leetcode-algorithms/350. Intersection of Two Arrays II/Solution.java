class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if ((nums1.length == 0) || (nums2.length == 0)) return new int[0];

        List<Integer> rslt = new ArrayList<>();
        Map<Integer, Integer> vmap1 = new HashMap<>();
        for (int i : nums1) vmap1.put(i, vmap1.getOrDefault(i, 0) + 1);

        Map<Integer, Integer> vmap2 = new HashMap<>();
        for (int i : nums2) vmap2.put(i, vmap2.getOrDefault(i, 0) + 1);

        for (Map.Entry<Integer, Integer> entry : vmap1.entrySet()) {
            if (vmap2.containsKey(entry.getKey())) {
                int times = Math.min(entry.getValue(), vmap2.get(entry.getKey()));

                for (int i = 0; i < times; i++){
                    rslt.add(entry.getKey());
                }
            }
        }

        int [] r = new int[rslt.size()];
        for (int i = 0; i < rslt.size(); i++) r[i] = rslt.get(i);
        return r;
    }
}
