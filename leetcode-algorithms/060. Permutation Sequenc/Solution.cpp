// The set [1,2,3,...,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note:
//
// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:
//
// Input: n = 3, k = 3
// Output: "213"
// Example 2:
//
// Input: n = 4, k = 9
// Output: "2314"
class Solution {
public:
    string getPermutation(int n, int k) {

        vector<char> vec;
        for (int i = 1; i <= n; i++) vec.push_back('0' + i);
        return impl(vec, k);
    }

    string impl(vector<char>& vec, int k) {
        if (vec.empty()) return "";
        string rslt = "";
        int n = vec.size();
        int t = 1;
        for (int i = 1; i < n; i++) t *= i;

        rslt += vec[(k - 1) / t];
        vec.erase(vec.begin() + (k - 1) / t);

        rslt += impl(vec, (k - 1) % t + 1);
        return rslt;
    }
};
