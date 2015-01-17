#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>

using std::string;
using std::vector;

bool str_cmp(string s1, string s2) {
    return (s1+s2).compare(s2+s1) > 0;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> vec;
        for(vector<int>::iterator it=num.begin(); it!=num.end(); it++) {
            vec.push_back(std::to_string(*it));
        }
        std::sort(vec.begin(), vec.end(), str_cmp);

        string ret;
        for(vector<string>::iterator it = vec.begin(); it!=vec.end(); it++) {
            if(ret.empty() && *it == "'0") continue;
            ret += *it;
        }
        if(ret.empty()) ret='0';
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int a[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> v(a, a+100);

    Solution *sl = new Solution();
    std::cout << sl->largestNumber(v) << std::endl;
    return 0;
}
