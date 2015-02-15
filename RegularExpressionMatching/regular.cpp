#include <iostream>

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') return *s=='\0';

        if(*(p+1) != '*') {
            return (*p == *s || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }

        while(*p==*s || (*p=='.' && *s!='\0')) {
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
};

int main(int argc, char *argv[])
{
    char s[] = "bb";
    char p[] = "b*bb";

    Solution * sl = new Solution();
    std::cout << sl->isMatch(s, p ) << std::endl;

    return 0;
}
