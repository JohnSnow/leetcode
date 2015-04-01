#include <string>
#include <unordered_set>
#include <vector>


using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> t(s.size() + 1,0);
        t[0] = true;

        int length = s.size();

        for(int i=0; i< length; i++) {
            if(!t[i]) continue;

            for(string seg: dict) {
                int len = seg.size();
                int end = i + len;
                if(end > length || t[end]) continue;

                if(s.compare(i, len, seg) == 0) {
                    t[i+len] = true;
                }
            }
        }
        return t[length];
    }
};


int main(int argc, char *argv[])
{
    string s("ab");
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("b");

    Solution * sl = new Solution();
    sl->wordBreak(s, dict);
    return 0;
}
