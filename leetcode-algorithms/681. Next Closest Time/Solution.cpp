// Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
//
// You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
//
// Example 1:
//
// Input: "19:34"
// Output: "19:39"
// Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
// Example 2:
//
// Input: "23:59"
// Output: "22:22"
// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> dig;
        dig.push_back(time[0] - '0');
        dig.push_back(time[1] - '0');
        dig.push_back(time[3] - '0');
        dig.push_back(time[4] - '0');

        set<int> se(dig.begin(), dig.end());
        if (se.size() == 1) {
            return time;
        }
        orgtime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        string temp;
        string rslt;
        int mindiff = INT_MAX;
        travel(dig, 0, temp, mindiff, rslt);
        //rslt.insert(2, ':');
        string s = rslt.substr(0, 2) + ':' + rslt.substr(2, 2);
        return s;
    }

    void travel(vector<int>& dig, int pos, string& temp, int& mindiff, string& rslt) {
        if (pos == dig.size()) {
            int curtime = stoi(temp.substr(0, 2)) * 60 + stoi(temp.substr(2, 2));
            if (curtime > orgtime) {
                int diff = curtime - orgtime;
                if (diff < mindiff) {
                    mindiff = diff;
                    rslt = temp;
                }
            } else if (curtime < orgtime) {
                int diff = 24 * 60 - orgtime + curtime;
                if (diff < mindiff) {
                    mindiff = diff;
                    rslt = temp;
                }
            }
            return;
        }

        for (int i = 0; i < dig.size(); i++) {
            if ((pos == 0) && (dig[i] > 2)) continue;
            if ((pos == 1) && (temp[0] == '2') && (dig[i] >= 4)) continue;
            if ((pos == 2) && (dig[i] >= 6)) continue;

            temp += (dig[i] + '0');
            travel(dig, pos + 1, temp, mindiff, rslt);
            temp.pop_back();
        }


    }

    int orgtime;
};
