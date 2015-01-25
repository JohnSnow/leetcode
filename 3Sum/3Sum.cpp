#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using std::vector;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > ans;
        if(num.size() < 3) return ans;

        std::sort(num.begin(), num.end());

        int last_one = INT_MIN;
        for(size_t i=0; i < num.size() -2; i++) {
            if(num[i] == last_one) continue;
            last_one = num[i];

            size_t j, k;
            for(j = i+1, k = num.size() -1; j < k; ) {

                if(num[j] + num[i] > 0) break;

                if(num[j] + num[k] == -num[i]) {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    ans.push_back(v);
                    int j_last = num[j]; int k_last = num[k];
                    j++; k--;
                    while(j < k && num[j] == j_last) j++; 
                    while(j< k && num[k] == k_last) k--;
                }
                else if(num[j] + num[k] < - num[i]) {
                    int j_last = num[j]; 
                    j++;
                    while(j < k && num[j] == j_last) j++; 
                }
                else {
                    int k_last = num[k];
                    k--;
                    while(j< k && num[k] == k_last) k--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    int a[] = {0,3,0,1,1,-1,-5,-5,3,-3,-3,0};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

    Solution *sl = new Solution();
    vector<vector<int> > ans = sl->threeSum(v);

    for(size_t i=0; i< ans.size(); i++) {
        for(size_t j=0; j< ans[i].size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout <<std::endl;
    }
    return 0;
}
