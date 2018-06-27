// Given a non-empty array of integers, return the k most frequent elements.
//
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class item {
public:
    item(int value, int times) {
        this->value = value;
        this->times = times;
    }
    int value;
    int times;
};

class cmp {
public:
    bool operator()(const item& a, const item& b) {
        return a.times > b.times;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;

        for (auto v : nums) count[v]++;

        priority_queue<item, vector<item>, cmp> que;

        map<int, int>::iterator iter = count.begin();

        for (; iter != count.end(); iter++) {
            item i(iter->first, iter->second);
            if (que.size() < k) que.push(i);
            else if (que.top().times < i.times) {
                que.pop();
                que.push(i);
            }
        }

        vector<int> rslt;
        while (!que.empty()) {
            rslt.push_back(que.top().value);
            que.pop();
        }

        return rslt;
    }
};
