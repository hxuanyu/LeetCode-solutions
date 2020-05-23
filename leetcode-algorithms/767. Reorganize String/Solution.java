class queitem {
    public queitem(char c, int times) {
        this.c = c;
        this.times = times;
    }
    int times = 0;
    char c;
}

class Solution {
    public String reorganizeString(String S) {
        if (S.length() <= 1) return S;

        Map<Character, Integer> cmap = new HashMap<>();
        int maxf = 0;
        for (char c : S.toCharArray()) {
            cmap.put(c, cmap.getOrDefault(c, 0) + 1);
            maxf = Math.max(maxf, cmap.get(c));
        }

        if (maxf > (S.length() + 1) / 2) return "";

        PriorityQueue<queitem> que = new PriorityQueue<>((i1, i2) -> i2.times - i1.times);

        for (Map.Entry<Character, Integer> entry : cmap.entrySet()) {
            que.add(new queitem(entry.getKey(), entry.getValue()));
        }

        StringBuilder sb = new StringBuilder();
        while (!que.isEmpty()) {
            if (sb.length() == 0 || sb.charAt(sb.length() - 1) != que.peek().c) {
                queitem top = que.poll();
                sb.append(top.c);
                top.times--;
                if (top.times > 0) que.add(top);
            } else {
                queitem top = que.poll();
                queitem second = que.poll();
                sb.append(second.c);
                second.times--;
                if (second.times > 0) que.add(second);
                que.add(top);
            }
        }

        return sb.toString();
    }
}
