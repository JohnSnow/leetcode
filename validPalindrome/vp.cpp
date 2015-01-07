#include <iostream>
#include <cctype>
#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {

        if(s.empty()) { return true; }

        string::const_iterator left_it;
        string::const_iterator right_it;

        for(left_it = s.begin(),right_it = s.end() - 1; left_it <= right_it; left_it++, right_it--)
        {
            while(!isalnum(*left_it) && left_it <= right_it) {
                left_it++;
            }
            while(!isalnum(*right_it) && right_it >= left_it) {
                right_it--;
            }
            if (left_it > right_it) {
                break;
            }
            if(tolower(*left_it) != tolower(*right_it)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout << sl->isPalindrome(string("A man, a plan, a canal: Panama")) << std::endl;
    std::cout << sl->isPalindrome(string(" ")) << std::endl;
    std::cout << sl->isPalindrome(string("a a")) << std::endl;
    std::cout << sl->isPalindrome(string("1a2")) << std::endl;
    return 0;
}
