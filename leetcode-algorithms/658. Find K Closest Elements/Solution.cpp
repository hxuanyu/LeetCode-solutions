// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
//
// Example 1:
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
// Example 2:
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
// Note:
// The value k is positive and will always be smaller than the length of the sorted array.
// Length of the given array is positive and will not exceed 104
// Absolute value of elements in the array and x will not exceed 104
// UPDATE (2017/9/19):
// The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.
struct item {
    item(int _val, int _idx) { val = _val; idx = _idx; }
    int val;
    int idx;
};

class cmp {
public:
    bool operator()(item& a, item& b) {
        return abs(a.val) < abs(b.val);
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        for (auto& v : arr) {
            v -= x;
        }

        priority_queue<item, vector<item>, cmp> queue;
        for (int i = 0; i < arr.size(); i++) {
            item it(arr[i], i);
            if (queue.size() < k) queue.push(it);
            else if (abs(arr[i]) < abs(queue.top().val)) {
                queue.pop();
                queue.push(it);
            }
        }

        multiset<int> se;
        while (!queue.empty()) {
            auto& item = queue.top();
            se.insert(item.idx);
            queue.pop();
        }

        vector<int> rslt;
        for (auto v : se) rslt.push_back(arr[v] + x);
        return rslt;
    }
};
