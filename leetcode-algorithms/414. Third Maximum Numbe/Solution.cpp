// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
//
// Example 1:
// Input: [3, 2, 1]
//
// Output: 1
//
// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]
//
// Output: 2
//
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]
//
// Output: 1
//
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> queue;
        for (auto v : nums) {
            if (queue.count(v)) continue;
            if (queue.size() < 3) queue.insert(v);
            else {
                int smallestin3 = *(queue.begin());
                if (v > smallestin3) {
                    queue.erase(queue.begin());
                    queue.insert(v);
                }
            }
        }

        if (queue.size() == 3) return *(queue.begin());
        else return *(--queue.end());
    }
};

// second solution
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        set<int> se(nums.begin(), nums.end());
        for (auto v : se) {
            if (v > first) {
                third = second;
                second = first;
                first = v;
            } else if (v > second) {
                third = second;
                second = v;
            } else if (v > third) {
                third = v;
            }
        }

        if (se.size() >= 3) return third;
        else return first;
    }
};
