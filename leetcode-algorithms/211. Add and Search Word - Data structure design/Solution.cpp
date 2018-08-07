//
// Design a data structure that supports the following two operations:
//
// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.

class TrieNode {
public:
    bool bleafe;
    vector<TrieNode*> children;
    TrieNode() : bleafe(false), children(26, nullptr) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ro = root;
        for (auto c : word) {
            if (ro->children[c - 'a'] == nullptr) {
                ro->children[c - 'a'] = new TrieNode();
            }
            ro = ro->children[c - 'a'];
        }
        ro->bleafe = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchFromNode(root, word, 0);
    }

    bool searchFromNode(TrieNode* node, string& word, int pos) {
        if (node == nullptr) return false;
        if (word.size() == pos) return node->bleafe;
        if (word[pos] == '.') {
            for (auto child : node->children) {
                if (searchFromNode(child, word, pos + 1)) return true;
            }
            return false;
        } else {
            if (node->children[word[pos] - 'a'] == nullptr) return false;
            else return searchFromNode(node->children[word[pos] - 'a'], word, pos + 1);
        }
    }

    TrieNode* root;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie.insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie.search(word);
    }

    Trie trie;
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
