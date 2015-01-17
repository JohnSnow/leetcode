#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int start = -1;
        int totalSum = 0;
        int sum = 0;
        vector<int>::iterator g_it, c_it;
        vector<int>::iterator g_begin = gas.begin();

        for(g_it = gas.begin(), c_it = cost.begin(); g_it != gas.end() && c_it != cost.end(); g_it++, c_it++) {
            sum += *g_it - *c_it;
            totalSum += *g_it - *c_it;
            if(sum < 0) {
                start = -1;
                sum = 0;
            } else if(start == -1) {
                start = g_it - g_begin;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};


int main(int argc, char *argv[])
{

    int a1[2] = {2, 4};
    int a2[2] = {3, 4};
    vector<int> v1(a1, a1+2);
    vector<int> v2(a2, a2+2);
    Solution *sl = new Solution();
    std::cout << sl->canCompleteCircuit(v1, v2) << std::endl;
    return 0;
}
