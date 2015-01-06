#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) {
            return 0;
        }

        char c;
        unsigned start = 0;
        unsigned c_cnt = 0;
        unsigned result = 0;
        unsigned i;

        // find M
        c = s[0];
        if(c == 'M') {
            c_cnt = 1;
            for(i = start + 1; s[i] == c && i < s.length(); i++)
                c_cnt++;

            result += 1000*c_cnt;
            start = i;
            c = s[start];
        }


        if (c== 'D') {
            result += 500;
            start += 1;
            c = s[start];
        }

        if(c == 'C') {
            if (s[start + 1] == 'M') {
                result += 900;
                start += 2;
            } else if(s[start + 1] == 'D') {
                result += 400;
                start += 2;
            } else {
                c_cnt = 1;
                for(i = start+1;s[i] == c && i < s.length(); i++) {
                    c_cnt++;
                }
                result += 100 * c_cnt;
                start = i;
            }
            c = s[start];
        }

        if(c=='L') {
            result += 50;
            start += 1;
            c = s[start];
        }

        if(c== 'X') {
            if(s[start+1] == 'C') {
                result += 90;
                start +=2;
            }else if (s[start + 1] == 'L') {
                result += 40;
                start +=2;
            }else{
                c_cnt = 1;
                for(i = start+1;s[i] == c && i < s.length(); i++) {
                    c_cnt++;
                }
                result += 10 *c_cnt;
                start = i;
            }
            c = s[start];
        }

        if (c == 'V') {
            result += 5;
            start += 1;
            c = s[start];
        }

        if(c == 'I') {
            if(s[start+1] == 'X') {
                result += 9;
                start += 2;
            }else if(s[start +1] == 'V') {
                result += 4;
                start += 2;
            } else {
                for(i = start+1;s[i] == c && i < s.length(); i++) {
                    c_cnt++;
                }
                result += c_cnt;
            }
        }
        return result;
    }

    bool roman(string s, size_t start, )

};
