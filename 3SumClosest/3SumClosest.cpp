#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>


using std::vector;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int last_one = INT_MIN;
        int sum = -100000;

        std::sort(num.begin(), num.end());

        for(unsigned i=0; i< num.size() -2; i++) {
            if(sum == target) break;
            if(num[i] == last_one) continue;
            last_one = num[i];

            unsigned j, k;
            for(j=i+1, k= num.size() - 1; j < k;) {
                int tmpSum = num[i] + num[j] + num[k];
                if(tmpSum == target) {
                    sum = target;
                    break;
                }
                else if(tmpSum > target) {
                     k--;
                }
                else{
                    j++;
                }
                if(abs(target - tmpSum) < abs(target - sum)) {
                    sum = tmpSum;
                }
            }
        }
        return sum;
    }
};


int main(int argc, char *argv[])
{
    Solution * sl = new Solution();
    int a[]={0,1,2};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

    std::cout << sl->threeSumClosest(v, 0) << std::endl;
    return 0;
}
