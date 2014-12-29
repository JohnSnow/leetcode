#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int majorityElement(vector<int> &num) {
        int det;
        unsigned count = 0;
        for (vector<int>::const_iterator _it = num.begin() ; _it != num.end(); _it++)
        {
            if(count == 0)
            {
                det = *_it;
                count++;
            }
            else if(*_it == det)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        return det;
    }
};


int main(int argc, char *argv[])
{
    int a[7] = {1,2,1,1,2,1,3};
    std::vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution *sl = new Solution();
    std::cout << sl->majorityElement(v) << std::endl;
    return 0;
}

