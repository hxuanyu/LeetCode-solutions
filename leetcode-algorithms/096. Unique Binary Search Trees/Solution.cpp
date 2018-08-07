// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
class Solution {
public:
    int numTrees(int n) {
        return impl(1, n);
    }

    int impl(int start, int end) {
        if (start == end) return 1;
        if (vmap.count(make_pair(start, end))) return vmap[make_pair(start, end)];

        int total = 0;
        for (int i = start + 1; i <= end - 1; i++) {
            total += impl(start, i - 1) * impl(i + 1, end);
        }
        total += impl(start + 1, end);
        total += impl(start, end - 1);

        vmap[make_pair(start, end)] = total;
        return total;
    }
    map<pair<int, int>, int> vmap;
};
