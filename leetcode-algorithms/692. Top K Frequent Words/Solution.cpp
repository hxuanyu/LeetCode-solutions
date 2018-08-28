// Given a non-empty list of words, return the k most frequent elements.
//
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
//
// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.
struct data {
    data(string val_, int count_) { val = val_; count = count_; }
    string val;
    int count;
};

class cmp {
public:
    bool operator()(data& a, data& b) {
        if (a.count == b.count) {
            return a.val < b.val;
        } else return a.count > b.count;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> smap; // word->count;

        for (auto word: words) {
            smap[word]++;;
        }

        priority_queue<data, vector<data>, cmp> queue;

        for (auto item : smap) {
            queue.push(data(item.first, item.second));
            if (queue.size() > k) queue.pop();
        }

        vector<string> rslt;
        while (!queue.empty()) {
            rslt.insert(rslt.begin(), queue.top().val);
            queue.pop();
        }
        return rslt;
    }
};
