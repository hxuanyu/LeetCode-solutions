// Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
//
// Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
//
// Example:
// Input:
// paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
// banned = ["hit"]
// Output: "ball"
// Explanation:
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"),
// and that "hit" isn't the answer even though it occurs more because it is banned.
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        map<string, int> vmap;
        map<int, set<string>> countmap;
        set<string> vbanned(banned.begin(), banned.end());
        stringstream ss(paragraph);
        string word;
        while (ss >> word) {
            string temp = "";
            for (auto c : word) {
                if (!((c == '!') || (c == '?') || (c == '\'') || (c == ',') || (c == ';') || (c == '.'))) {
                    if (('a' <= c) && (c <= 'z')) temp += c;
                    else temp += char(c - 'A' + 'a');
                }
            }
            if (vbanned.count(temp)) continue;
            vmap[temp]++;
            int count = vmap[temp];
            countmap[count].insert(temp);
            if (countmap.count(count - 1)) countmap[count - 1].erase(temp);
        }

        map<int, set<string>>::iterator iter = countmap.end();
        iter = --iter;
        for (auto c : (iter->second)) return c;
    }
};
