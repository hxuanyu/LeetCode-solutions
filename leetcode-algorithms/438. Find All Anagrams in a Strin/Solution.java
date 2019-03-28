class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> rslt = new ArrayList<>();
        for (int i = 0; i <= s.length() - p.length(); i++) {
        	if (good(s, p, i)) rslt.add(i);
        }
        return rslt;
    }

    private boolean good(String s, String p, int pos) {
    	int [] ar = new int[26];

    	for (int idx = 0; idx < p.length(); idx++) {
    		ar[p.charAt(idx) - 'a']++;
    		ar[s.charAt(pos + idx) - 'a']--;
    	}

    	for (int i = 0; i < ar.length; i++) {
    		if (ar[i] != 0) return false;
    	}

    	return true;
    }
}
