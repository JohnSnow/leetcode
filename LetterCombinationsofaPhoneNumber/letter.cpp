#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::string;

class Solution {
public:
/*    vector<string> letterCombinations(string digits) {*/
        //vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //vector<string> ans;
        //size_t m = 1, n = digits.size();
        //for (auto &c: digits)
            //m *= dict[c - '0'].length();
        //for (size_t i = 0; i < m; i ++) {
            //size_t p = i;
            //string s = "";
            //for (size_t j = 0; j < n; j ++) {
                //int c = digits[j] - '0';
                //int base = dict[c].length();
                //int v = p % base;
                //s += dict[c][v];
                //p /= base;
            //}
            //ans.push_back(s);
        //}
        //return ans;
    /*}*/

    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        ans.push_back("");
        for(auto &c : digits) {
            vector<string> tmp;
            for(auto i=0; i< dict[c-'0'].length(); i++) {
                char b = dict[c-'0'][i];
                for(string &s1:ans) {
                    tmp.push_back(s1 + b);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution *sl = new Solution();

    vector<string> ret = sl->letterCombinations(string("23"));

    for(vector<string>::iterator it = ret.begin(); it!=ret.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
