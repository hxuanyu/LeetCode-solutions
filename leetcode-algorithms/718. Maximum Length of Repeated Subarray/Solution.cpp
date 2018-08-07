// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//
// Example 1:
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation:
// The repeated subarray with maximum length is [3, 2, 1].
// Note:
// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> vals(A.size() + 1, vector<int>(B.size() + 1, 0));
        int maxlen = 0;

        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = B.size() - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    vals[i][j] = 1 + vals[i + 1][j + 1];
                    maxlen = max(maxlen, vals[i][j]);
                }
            }
        }
        return maxlen;
    }
};
