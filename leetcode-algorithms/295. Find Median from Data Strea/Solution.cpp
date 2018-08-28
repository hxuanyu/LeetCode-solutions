//
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
// For example,
// [2,3,4], the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Design a data structure that supports the following two operations:
//
// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
//
//
// Example:
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3)
// findMedian() -> 2
//
//
// Follow up:
//
// If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (smallpart.empty()) smallpart.push(num);
        else {
            if (smallpart.top() < num) {
                largepart.push(num);
            } else {
                smallpart.push(num);
            }
        }

        while (smallpart.size() > largepart.size() + 1) {
            largepart.push(smallpart.top());
            smallpart.pop();
        }

        while (largepart.size() > smallpart.size() + 1) {
            smallpart.push(largepart.top());
            largepart.pop();
        }
    }

    double findMedian() {
        if (largepart.empty() && smallpart.empty()) return 0;

        if (largepart.size() == smallpart.size()) return (largepart.top() + smallpart.top()) / 2.0;
        else if (largepart.size() > smallpart.size()) return largepart.top();
        else return smallpart.top();
    }

    priority_queue<int> smallpart;
    priority_queue<int, vector<int>, greater<int>> largepart;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
