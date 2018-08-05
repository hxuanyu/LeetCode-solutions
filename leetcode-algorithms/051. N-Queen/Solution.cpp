// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        set<pair<int, int>> temp;
        set<set<pair<int, int>>> rslt;
        travel(0, n, temp, rslt);

        vector<vector<string>> rslts;
        for (auto sln : rslt) {
            string s(n, '.');
            vector<string> slns(n, s);
            for (auto pos : sln) {
                slns[pos.first][pos.second] = 'Q';
            }
            rslts.push_back(slns);
        }

        return rslts;
    }

    void travel(int row, int n, set<pair<int, int>>& temp, set<set<pair<int, int>>>& rslt) {
        if (temp.size() == n) {
            rslt.insert(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (bvalid(temp, row, j)) {
                temp.insert(make_pair(row, j));
                travel(row + 1, n, temp, rslt);
                temp.erase(make_pair(row, j));
            }
        }
    }

    bool bvalid(set<pair<int, int>>& current, int row, int col) {
        for (auto item : current) {
            if ((item.first == row) || (item.second == col) || (abs(item.first - row) == abs(item.second - col))) return false;
        }
        return true;
    }
};
