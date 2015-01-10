#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return string("");

        string common = strs[0];
        vector<string>::const_iterator it;
        for(it=strs.begin() + 1; it!=strs.end(); ++it) {
            common = commonPrefix(common, *it);
            if(common.empty()) return string("");
        }
        return common;
    }

    string commonPrefix(string s1, string s2) {
        string::const_iterator it1, it2;
        for(it1=s1.begin(), it2=s2.begin(); it1 !=s1.end() && it2!=s2.end(); ++it1, ++it2)
        {
            if(*it1 != *it2) break;
        }
        if(it1 == s1.end()) return s1;
        if(it2 == s2.end()) return s2;

        return s1.substr(0, it1 - s1.begin());
    }


};
