// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// Example 1:
//
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:
//
// Input: [[7,10],[2,4]]
// Output: 1
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class cmp {
public:
    bool operator()(const Interval& a, const Interval& b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return int(intervals.size());

        sort(intervals.begin(), intervals.end(), cmp());

        multiset<int> endtime;
        endtime.insert(intervals[0].end);
        int maxamount = 1;

        for (int i = 1; i < intervals.size(); i++) {
            int earliestend = *(endtime.begin());
            if (intervals[i].start < earliestend) {
                endtime.insert(intervals[i].end);
                maxamount = max(maxamount, int(endtime.size()));
            } else {
                endtime.erase(endtime.begin());
                endtime.insert(intervals[i].end);
            }
        }

        return maxamount;
    }
};
