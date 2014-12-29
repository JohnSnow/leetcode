#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::string;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if(numerator == 0) return std::to_string(0);
        long num, den;

        int sign1 = 1;
        if (numerator < 0) {
            sign1 = -1;
        }
        num = (long)numerator * sign1;
        int sign2 = 1;
        if (denominator < 0) {
            sign2 = -1;
        }
        den = (long)denominator * sign2;
        int sign = sign1*sign2;

        unsigned q = num % den;
        long fac = num/ den;
        string ret = std::to_string(fac);

        if(q  == 0) {
            return sign==-1?"-"+ret:ret;
        }

        num = q;
        int gd = gcd(num, den);
        if(gd > 1)
        {
            num /= gd;
            den /= gd;
        }

        std::unordered_map<int, int> _map;
        std::vector<int> v;
        std::unordered_map<int, int>::iterator _map_it;
        bool finite = true;

        while (true)
        {
            num *= 10;
            int q1 = num % den;
            int a1 = num / den;

            _map_it = _map.find(num);
            if (_map_it != _map.end()) {
                finite = false;
                break;
            }

            v.push_back(num);

            _map[num] = a1;

            if (q1 == 0) break;

            num= q1;
        }

        ret += ".";
        if(finite) {
            for(std::vector<int>::iterator it=v.begin(); it!=v.end(); it++)
            {
                ret += std::to_string(_map[*it]);
            }
        }
        else
        {
            std::vector<int>::iterator _it = std::find(v.begin(), v.end(), (*_map_it).first);
            for(std::vector<int>::iterator it = v.begin(); it!=_it; it++)
            {
                ret += std::to_string(_map[*it]);
            }
            ret += "(";
            for(std::vector<int>::iterator it = _it; it != v.end(); it++)
            {
                ret += std::to_string(_map[*it]);
            }
            ret += ")";
        }
        
         return sign==-1?"-"+ret:ret;
    }

    int gcd(int x, int y)
    {
        int q;
        while((q = y%x) != 0)
        {
            y = x;
            x = q;
        }
        return x;
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout << sl->fractionToDecimal(-2147483648, 1) << std::endl;
    return 0;
}
