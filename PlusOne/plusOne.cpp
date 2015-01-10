#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {

        bool plus = false;
        for(vector<int>::reverse_iterator it=digits.rbegin(); it != digits.rend(); it++)
        {
            ++(*it);
            plus = false;
            if(*it < 10) break;
            if(*it == 10) {
                *it = 0;
                plus = true;
            }
        }
        if(plus) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main()
{
    Solution *sl = new Solution();
    vector<int> vec;
    vec.push_back(9);
    sl->plusOne(vec);
    return 0;
}
