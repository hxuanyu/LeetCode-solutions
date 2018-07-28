// A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//
// Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
//
// We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
//
// Example 1:
// Input:
// ["9001 discuss.leetcode.com"]
// Output:
// ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
// Explanation:
// We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
//
// Example 2:
// Input:
// ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
// Output:
// ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
// Explanation:
// We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
//
// Notes:
//
// The length of cpdomains will not exceed 100.
// The length of each domain name will not exceed 100.
// Each address will have either 1 or 2 "." characters.
// The input count in any count-paired domain will not exceed 10000.
// The answer output can be returned in any order.
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> vmap;
        for (auto domain : cpdomains) {
            int times = 0;
            vector<string> subs = parserecord(domain, times);
            for (auto sub : subs) vmap[sub] += times;
        }

        vector<string> rslt;
        for (auto item : vmap) {
            rslt.push_back(std::to_string(item.second) + " " + item.first);
        }

        return rslt;
    }

    vector<string> parserecord(string cp, int& times) {
        int whitepos = cp.find(' ');
        times = std::stoi(cp.substr(0, whitepos));

        string domain = cp.substr(whitepos + 1, string::npos);

        vector<string> rslt;
        size_t endpos = domain.length() - 1;
        size_t pos = endpos;
        while ((pos = domain.find_last_of(".", pos)) != string::npos) {
            string sub = domain.substr(pos + 1, endpos - pos);
            pos -= 1;
            rslt.push_back(sub);
        }
        rslt.push_back(domain);
        return rslt;
    }
};
