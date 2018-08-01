// Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
//
// If there is no answer, return the empty string.
// Example 1:
// Input:
// words = ["w","wo","wor","worl", "world"]
// Output: "world"
// Explanation:
// The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
// Example 2:
// Input:
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation:
// Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
// Note:
//
// All the strings in the input will only contain lowercase letters.
// The length of words will be in the range [1, 1000].
// The length of words[i] will be in the range [1, 30].
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

class Solution {
public:
    string longestWord(vector<string>& words) {
        std::sort(words.begin(), words.end());
        Trie trie;

        set<string> maxlenset;
        for (auto word : words) trie.insert(word);
        int maxlen = 0;
        for (auto word : words) {
            int i = 0;
            for (; i < word.size(); i++) {
                string sub = word.substr(0, i + 1);
                if (!trie.search(sub)) break;
            }
            if (i == word.size()) {
                if (word.size() > maxlen) {
                    maxlen = word.size();
                    maxlenset.clear();
                    maxlenset.insert(word);
                } else if (word.size() == maxlen) {
                    maxlenset.insert(word);
                }
            }
        }

        return *(maxlenset.begin());
    }
};
