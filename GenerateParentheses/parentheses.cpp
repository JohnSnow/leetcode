#include <string>
#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::string;
using std::stack;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        if(n==0) return ans;

        stack<char> st;
        string s;
        st.push('(');
        s.push_back('(');
        generateR(n-1, st, s, ans);
        return ans;
    }

    void generateR(int n, stack<char> &st, string &s, vector<string> &ans)
    {
        if(n == 0) {
            string s0(s);
            for(auto i=0; i < st.size(); i++) {
                s0.push_back(')');
            }
            ans.push_back(s0);
            return;
        }
        if(!st.empty()) {
            st.pop();
            s.push_back(')');
            generateR(n, st, s, ans);
            st.push('(');
            s.pop_back();
        }

        st.push('(');
        s.push_back('(');
        generateR(n-1, st, s, ans);
        st.pop();
        s.pop_back();
    }
};

void printV(vector<string> ans, int n)
{
    std::cout << "number: " << n << std::endl;
    for(auto item : ans) {
        std::cout << item << std::endl;
    }
}

int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    for(int i=1; i< 4; i++) {
        vector<string> ans = sl->generateParenthesis(i);
        printV(ans, i);
    }

    return 0;
}
