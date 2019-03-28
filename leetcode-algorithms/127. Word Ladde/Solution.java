class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordlist = new HashSet<>(wordList);

        Queue<String> que = new LinkedList<>();
        que.add(beginWord);

        int dis = 1;
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                String top = que.poll();
                List<String> nei = new ArrayList<>();
                getnei(top, nei, wordlist);

                if (nei.contains(endWord)) return dis + 1;
                que.addAll(nei);
            }
            dis++;
        }

        return 0;
    }

    void getnei(String word, List<String> nei, Set<String> wordlist) {
        wordlist.remove(word);
        StringBuilder sb = new StringBuilder(word);

        for (int i = 0; i < sb.length(); i++) {
            char ch = sb.charAt(i);

            for (char c = 'a'; c <= 'z'; c++) {
                sb.setCharAt(i, c);
                if (wordlist.contains(sb.toString())) {
                    nei.add(sb.toString());
                    wordlist.remove(sb.toString());
                }
            }
            sb.setCharAt(i, ch);
        }
    }
}
