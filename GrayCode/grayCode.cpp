#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        for(int i=0; i < pow(2, n); i++) {
            vec.push_back(i>>1 ^ i);
        }
        return vec;
    }
};
