// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
// Example:
//
// Input:
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
//
// Output: ["eat","oath"]
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto word : words) trie.insert(word);

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        set<string> srslt;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string temp = "";
                vector<string> local;
                find(board, i, j, trie.root, temp, local, visited);
                //if (!local.empty()) std::copy(local.begin(), local.end(), rslt.begin());
                for (auto v : local) srslt.insert(v);
            }
        }

        vector<string> rslt(srslt.begin(), srslt.end());
        return rslt;
    }

    void find(vector<vector<char>>& board, int i, int j, TrieNode* node, string& temp, vector<string>& rslt, vector<vector<bool>>& visited) {
        if ((i < 0) || (j < 0) || (i >= board.size()) || (j >= board[0].size()) || (node == nullptr) || visited[i][j]) return;

        TrieNode* next = node->children[board[i][j] - 'a'];
        if (next == nullptr) return;
        temp += board[i][j];
        visited[i][j] = true;

        if (next->bleafe) rslt.push_back(temp);

        vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        for (auto dir : dirs) {
            find(board, i + dir[0], j + dir[1], next, temp, rslt, visited);
        }
        visited[i][j] = false;
        temp = temp.substr(0, temp.size() - 1);
    }
};
