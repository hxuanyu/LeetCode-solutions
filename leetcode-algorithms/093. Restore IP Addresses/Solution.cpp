// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rslt;
        vector<vector<string>> rsltv;
        vector<string> temp;
        travel(s, 0, temp, rsltv);

        for (auto v : rsltv) {
            string s = "";
            for (int i = 0; i < v.size(); i++) {
                s += v[i];
                if (i == v.size() - 1) break;
                s += '.';
            }
            rslt.push_back(s);
        }
        return rslt;
    }

    void travel(string& s, int pos, vector<string>& temp, vector<vector<string>>& rslt) {
        if (pos == s.size()) {
            if (temp.size() == 4) {
                rslt.push_back(temp);
                return;
            }
        } else if (pos > s.size()) return;
        else if (temp.size() > 4) return;

        if (s[pos] == '0') {
            temp.push_back("0");
            travel(s, pos + 1, temp, rslt);
            temp.pop_back();
        } else {
            for (int i = pos; i < min(pos + 4, int(s.size())); i++) {
                string sub = s.substr(pos, i - pos + 1);
                if (stoi(sub) <= 255) {
                    temp.push_back(sub);
                    travel(s, i + 1, temp, rslt);
                    temp.pop_back();
                }
            }
        }
    }
};
