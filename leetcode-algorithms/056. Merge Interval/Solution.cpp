// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
class cmp {
public:
    bool operator ()(const Interval& a, const Interval& b) {
        if (a.start < b.start) return true;
        else if (a.start > b.start) return false;
        else return a.end < b.end;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rslt;
        if (intervals.size() == 0) return rslt;
        sort(intervals.begin(), intervals.end(), cmp());

        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            int nextstart = intervals[i].start;

            if (end < nextstart) {
                Interval a(start, end);
                rslt.push_back(a);
                start = intervals[i].start;;
                end = intervals[i].end;
            } else {
                end = max(intervals[i].end, end);
            }
        }
        Interval a(start, end);
        rslt.push_back(a);

        return rslt;
    }
};
