// Implement an iterator to flatten a 2d vector.
//
// Example:
//
// Input: 2d vector =
// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// Output: [1,2,3,4,5,6]
// Explanation: By calling next repeatedly until hasNext returns false,
//              the order of elements returned by next should be: [1,2,3,4,5,6].
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d):idx(0), bend(true) {
        for (auto row : vec2d) {
            if (!row.empty()) vec.push_back(row);
        }

        if (vec.empty()) return;
        idx = 0;
        iter = vec[idx].begin();
        bend = false;
    }

    int next() {
        if (bend) return -1;

        int v = *(iter++);
        if (iter == vec[idx].end()) {
            idx++;

            if (idx != vec.size()) {
                iter = vec[idx].begin();
            } else {
                bend = true;
            }
        }

        return v;
    }

    bool hasNext() {
        return !bend;
    }

    vector<vector<int>> vec;
    int idx;
    vector<int>::iterator iter;
    bool bend;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
