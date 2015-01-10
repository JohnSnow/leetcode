#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        if (a.empty() && b.empty()) return ret;
        if (a.empty()) {
            return b;
        }else if (b.empty()) {
            return a;
        }

        unsigned size_a = a.size();
        unsigned size_b = b.size();

        if(size_a < size_b) {
            ret = b;
            b = a;
            a = ret;
        }

        unsigned plus = 0;
        string::reverse_iterator a_it, b_it;
        for(a_it = a.rbegin(), b_it=b.rbegin(); b_it !=b.rend(); b_it++, a_it++)
        {
            int sum = int(*a_it) - '0' + int(*b_it) - '0' + plus;
            *a_it = (sum & 0x1) + '0';
            sum>1? plus = 1 : plus =0;
        }

        if(a_it != a.rend()) {
            for(;a_it!=a.rend(); a_it++) {
                int sum = int(*a_it) - '0' + plus;
                *a_it = (sum & 0x1) + '0';
                sum > 1? plus = 1: plus = 0;
            }
        }

        if(plus) {
            a.insert(a.begin(), '1');
        }
        return a;
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    sl->addBinary(string("0"), string("0"));
    return 0;
}
