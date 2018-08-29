// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// Example:
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        total = 0;
    }

    double next(int val) {
        total += val;
        if (que.size() < size) que.push_back(val);
        else {
            total -= que.front();
            que.pop_front();
            que.push_back(val);
        }
        return double(total) / que.size();
    }

    int size;
    deque<int> que;
    int total;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
