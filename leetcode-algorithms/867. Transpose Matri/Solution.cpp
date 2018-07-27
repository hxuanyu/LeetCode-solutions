class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> rslt(A[0].size(), vector<int>(A.size(), 0));

        for (int i = 0; i < rslt.size(); i++) {
            for (int j = 0; j < rslt[0].size(); j++) {
                rslt[i][j] = A[j][i];
            }
        }

        return rslt;
    }
};
