// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        if (col == 0) return false;

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (find(board, word, 0, i, j, visited)) return true;
            }
        }

        return false;
    }

    bool find(vector<vector<char>>& board, string word, int pos, int i, int j, vector<vector<bool>>& visited) {
        if ((i < 0) || (j < 0) || (i >= board.size()) || (j >= board[0].size()) || visited[i][j] || (pos >= word.size())) return false;

        if (board[i][j] != word[pos]) return false;

        if (pos == word.size() - 1) return true;

        visited[i][j] = true;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto dir : dirs) {
            if (find(board, word, pos + 1, i + dir[0], j + dir[1], visited)) return true;
        }
        visited[i][j] = false;

        return false;
    }
};
