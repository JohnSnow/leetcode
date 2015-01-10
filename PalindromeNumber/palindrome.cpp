#include <iostream>
#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = 0;
        int a = x;
        while(a) {
            if(a <10 && n > INT_MAX/10) {
                return false;
            }
            n = n*10 + a % 10;
            a /=10;
        }
        return x == n;
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout<< sl->isPalindrome(1) << std::endl;
    return 0;
}
