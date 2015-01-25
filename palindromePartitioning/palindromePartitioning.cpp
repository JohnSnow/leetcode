#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> vec;
        recusivePartition(s, ans, vec);
        return ans;
    }

    void recusivePartition(string s, vector<vector<string> > &ans, vector<string> &v)
    {
        if(s.empty()) {
            ans.push_back(v);
            return;
        }

        for(size_t i=0; i< s.size(); i++) {

            if(isPalinDrome(s, 0, i)) {
                v.push_back(s.substr(0,i+1));
                string s2 = s.substr(i+1);
                recusivePartition(s2, ans, v);
                v.pop_back();
            }
        }
    }

    bool isPalinDrome(string &s, size_t start, size_t end) {
        if(s.empty()) return false;
        for(; start < end; start++, end--) {
            if(s[start] != s[end]) return false;
        }
        return true;
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    sl->partition(string("aab"));
    return 0;
}
