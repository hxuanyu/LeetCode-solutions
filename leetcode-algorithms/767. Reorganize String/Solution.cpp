// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible, return the empty string.
//
// Example 1:
//
// Input: S = "aab"
// Output: "aba"
// Example 2:
//
// Input: S = "aaab"
// Output: ""
// Note:
//
// S will consist of lowercase letters and have length in range [1, 500].
struct item {
    item(char c_, int count_) { c = c_; count = count_; }
    char c;
    int count;
};

class cmp {
public:
    bool operator()(const item& a, const item& b) { return a.count < b.count; }
};

class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> vmap;
        int maxc = 0;
        for (auto c : S) {
            vmap[c]++;
            maxc = max(maxc, vmap[c]);
        }

        if (maxc > (int(S.size()) + 1) / 2) return "";

        priority_queue<item, vector<item>, cmp> que;
        for (auto v : vmap) {
            que.push(item(v.first, v.second));
        }

        string rslt = "";
        while (!que.empty()) {
            auto top = que.top();
            que.pop();

            if ((rslt.size() == 0) || (rslt.back() != top.c)) {
                rslt += top.c;
                top.count--;
                if (top.count > 0) que.push(top);
            } else {
                auto second = que.top();
                que.pop();
                rslt += second.c;
                second.count--;
                if (second.count > 0) que.push(second);
                que.push(top);
            }
        }

        return rslt;
    }
};
