class TrieNode {

    public TrieNode() {
        isend = false;
        children = new TrieNode[26];
        for (int i = 0; i < 26; i++) children[i] = null;
    }
    boolean isend;
    TrieNode[] children;
}

class Trie {

    /** Initialize your data structure here. */
    public Trie() {

    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode node = root;

        for (int i = 0; i < word.length(); i++) {
            int idx = (int)(word.charAt(i) - 'a');
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }

            node = node.children[idx];
        }

        node.isend = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = (int)(word.charAt(i) - 'a');

            if (node.children[idx] == null) return false;
            else {
                node = node.children[idx];
            }
        }
        return node.isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = (int)(prefix.charAt(i) - 'a');

            if (node.children[idx] == null) return false;
            else {
                node = node.children[idx];
            }
        }
        return true;
    }

    TrieNode root = new TrieNode();
}

class WordDictionary {

    /** Initialize your data structure here. */
    public WordDictionary() {

    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
        trie.insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return implsearch(word, trie.root);
    }

    private boolean implsearch(String word, TrieNode node) {
        if (word.length() == 0) return (node != null) && (node.isend == true);

        char c = word.charAt(0);
        if (c != '.') {
            int idx = (int) (c - 'a');
            if (node.children[idx] == null) return false;
            return implsearch(word.substring(1), node.children[idx]);
        } else {
            for (TrieNode child : node.children) {
                if (child != null && implsearch(word.substring(1), child)) return true;
            }
            return false;
        }
    }

    Trie trie = new Trie();
}
