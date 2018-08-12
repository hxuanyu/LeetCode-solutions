// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                int subid = (i / 3) * 3 + j / 3;
                rowset[i].insert(board[i][j]);
                colset[j].insert(board[i][j]);
                subset[subid].insert(board[i][j]);
            }
        }
        travel(board, 0, 0);
    }

    bool travel(vector<vector<char>>& board, int i, int j) {
        if (i >= board.size()) return false;
        if (board[i][j] != '.') { // If already filled, go to next
            if ((i == (board.size() - 1)) && (j == (board[0].size() - 1))) return true;
            else if (j == (board[0].size() - 1)) return travel(board, i + 1, 0);
            else return travel(board, i, j + 1);
        } else {
            for (char v = '1'; v <= '9'; v++) {
                int subid = (i / 3) * 3 + j / 3;
                if ((!rowset[i].count(v)) && (!colset[j].count(v)) && (!subset[subid].count(v))) {
                    board[i][j] = v;
                    rowset[i].insert(v);
                    colset[j].insert(v);
                    subset[subid].insert(v);
                    if (travel(board, i, j)) return true;
                    rowset[i].erase(v);
                    colset[j].erase(v);
                    subset[subid].erase(v);
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }

    map<int, set<char>> rowset;
    map<int, set<char>> colset;
    map<int, set<char>> subset;

};
