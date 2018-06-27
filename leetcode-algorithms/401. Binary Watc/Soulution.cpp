// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//
// Each LED represents a zero or one, with the least significant bit on the right.
//
//
// For example, the above binary watch reads "3:25".
//
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
// Example:
//
// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
// Note:
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> v = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};

        vector<int> h;
        vector<int> m;
        vector<string> rslt;
        perm(v, 0, num, h, m, rslt);
        return rslt;
    }

    void perm(vector<int>&v, int cur, int total, vector<int>& h, vector<int>& m, vector<string>& rslt) {
        if (h.size() + m.size() == total) {
            int hour = 0;
            for (auto v : h) hour += v;
            if (hour > 11) return;

            int min = 0;
            for (auto v : m) min += v;
            if (min > 59) return;

            string sh = std::to_string(hour);
            string sm = (min == 0) ? "00" : ((min < 10 ? "0" : "") + std::to_string(min));
            rslt.push_back(sh + ":" + sm);
            return;
        }

        for (int i = cur; i < v.size(); i++) {
            if (i <= 3) h.push_back(v[i]);
            else m.push_back(v[i]);

            perm(v, i + 1, total, h, m, rslt);

            if (i <= 3) h.pop_back();
            else m.pop_back();
        }
    }
};
