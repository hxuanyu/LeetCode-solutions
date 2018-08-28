// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Example 1:
//
// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
// Example 2:
//
// Input: version1 = "1.0.1", version2 = "1"
// Output: 1
// Example 3:
//
// Input: version1 = "7.5.2.4", version2 = "7.5.3"
// Output: -1
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> subv1 = split(version1);
        vector<int> subv2 = split(version2);
        int i = 0;
        for (; i < min(subv1.size(), subv2.size()); i++) {
            if (subv1[i] == subv2[i]) continue;
            return subv1[i] > subv2[i] ? 1 : -1;
        }

        if ((i == subv1.size()) && (i == subv2.size())) return 0; // both done
        else if (i == subv2.size()) {
            for (; i < subv1.size(); i++) {
                if (subv1[i] != 0) return 1;
            }
            return 0;
        } else {
            for (; i < subv2.size(); i++) {
                if (subv2[i] != 0) return -1;
            }
            return 0;
        }
    }

    vector<int> split(string ver) {
        vector<int> rslt;
        std::size_t dotpos = 0;
        do {
            dotpos = ver.find('.');
            if (dotpos == string::npos) {
                rslt.push_back(stoi(ver));
                return rslt;
            }

            rslt.push_back(stoi(ver.substr(0, dotpos)));
            ver = ver.substr(dotpos + 1, string::npos);
        } while (true);
    }
};
