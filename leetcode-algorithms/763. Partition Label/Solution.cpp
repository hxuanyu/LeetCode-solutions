// A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
// Example 1:
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
// Note:
//
// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.
class Solution {
public:
    vector<int> partitionLabels(string S) {
        return partimpl(S);
    }

    vector<int> partimpl(string&s) {
        map<char, int> vmap;
        for (int i = 0; i < s.length(); i++) {
            vmap[s[i]]++;
        }
        vector<int> rslt;
        int start = 0;
        do {
            set<char> cset;
            int total = 0;
            int i = start;
            for (; i < s.length(); i++) {
                char toremove = s[i];
                if (!cset.count(toremove)) {
                    total += vmap[toremove];
                    cset.insert(toremove);
                }
                total--;
                //cset.insert(toremove);
                vmap[s[i]]--;
                if (vmap[s[i]] == 0) vmap.erase(s[i]);
                if (total == 0) break;
            }
            rslt.push_back(i - start + 1);
            start = i + 1;
        } while (start < s.length());

        return rslt;
    }
};
