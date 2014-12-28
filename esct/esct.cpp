#include<string>

using std::string;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n)
        {
            unsigned t = (n - 1) % 26 + 1;
            s = char(t + 64) + s;
            n = (n - t) / 26;
        }
        return s;
    }
};
