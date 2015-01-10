#include <iostream>
#include <climits>

class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return 0;

        while(*str == ' ') str++;

        int posneg = 0;
        int ret = 0;

        if(*str=='-') {
            posneg = -1;
            str++;
        } else if(*str == '+') {
            posneg = 1;
            str++;
        }

        if(!isdigit(*str)) return 0;

        while(isdigit(*str)) {
            if(ret >INT_MAX/10 || 
                    (ret == INT_MAX/10 && (*str-'0') > INT_MAX % 10)) {
                if(posneg == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            ret = ret * 10 + *str - '0';
            str++;
        }
        return posneg * ret;
    }
};
