// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:
//
// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.
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
        TrieNode* ro = root;
        for (auto c : word) {
            if (ro->children[c - 'a'] == nullptr) return false;
            ro = ro->children[c - 'a'];
        }

        return ro->bleafe;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ro = root;
        for (auto c : prefix) {
            if (ro->children[c - 'a'] == nullptr) return false;
            ro = ro->children[c - 'a'];
        }

        return true;
    }

    TrieNode* root;
};
