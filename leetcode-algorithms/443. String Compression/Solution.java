class Solution {
    public int compress(char[] chars) {
        List<Character> rslt = new ArrayList<>();

        int i = 0;
        int changepos = 0;
        while (i < chars.length) {
        	int p = i;

        	while ((p < chars.length) && (chars[i] == chars[p])) p++;

        	int len = p - i;

        	chars[changepos++] = chars[i];
        	if (len > 1) {
        		List<Character> dig = new ArrayList<>();
        		while (len > 0) {
        			dig.add((char)('0' + len % 10));
        			len = len / 10;
        		}

        		for (int j = dig.size() - 1; j >= 0; j--) {
        			chars[changepos++] = dig.get(j);
        		}
        	}

        	i = p;
        }

        return  changepos;

    }
}
