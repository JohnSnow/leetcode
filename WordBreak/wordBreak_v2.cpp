#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>


using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> t(s.size() + 1,false);
        t[0] = true;

        int length = s.size();

        for(int i=1; i< length + 1; i++) {

            for(int k=0; k<i; k++) {
                    t[i] = t[k] &&
                        dict.find(s.substr(k, i-k))!=dict.end();

                    if(t[i]) break;
                }
            }
        return t[length];
    }
};


int main(int argc, char *argv[])
{
    string s("a");
    unordered_set<string> dict;

    Solution * sl = new Solution();
    std::cout << sl->wordBreak(s, dict) << std::endl;
    return 0;
}
