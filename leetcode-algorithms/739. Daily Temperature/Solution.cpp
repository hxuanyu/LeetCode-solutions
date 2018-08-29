// Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
//
// For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
// Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
//
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> rslt(temperatures.size());
        //if (temperatures.size() <= 1) return rslt;

        vector<int> pos(101, INT_MAX);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            auto t = temperatures[i];

            int lastp = INT_MAX;
            for (auto v = t + 1; v <= 100; v++) {
                lastp = min(lastp, pos[v]);
            }
            if (lastp == INT_MAX) rslt[i] = 0;
            else rslt[i] = lastp - i;
            pos[t] = i;
        }

        return rslt;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> rslt(temperatures.size());

        stack<int> pos;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            auto t = temperatures[i];

            while ((pos.size() > 0) && (t >= temperatures[pos.top()])) pos.pop();
            if (pos.empty()) rslt[i] = 0;
            else rslt[i] = pos.top() - i;

            pos.push(i);
        }

        return rslt;
    }
};
