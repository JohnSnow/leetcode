#include <iostream>
#include <stack>
#include <string>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        if( (s.length() & 0x1) != 0) {
            return false;
        }

        std::stack<char> _stack;
        _stack.push('0');

        for(string::const_iterator it = s.begin(); it != s.end(); it++)
        {
            if(pair(_stack.top(), *it)) {
                _stack.pop();
            }else{
                _stack.push(*it);
            }
        }
        _stack.pop();
        return _stack.empty()? true: false;
    }

    bool inline pair(char c1, char c2) 
    {
        if((c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}') )
        {
            return true;
        }else{
            return false;
        }

    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout << sl->isValid(string("()")) << std::endl;
    return 0;
}
