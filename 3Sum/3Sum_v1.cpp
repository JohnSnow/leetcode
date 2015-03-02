#include <vector>
#include <algorithm>

using std::vector;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;

        vector<int> triplet(3,0);

        int len = num.size();
        if(len < 3) return ans;

        std::sort(num.begin(), num.end());

        for(int i=0; i< len - 2; i++) {
            if(i>0 && num[i] == num[i-1]) continue;

            int j = i+1, k = len - 1;
            int target = -num[i];

            while(j < k) {
                if(j > i+1 && num[j] == num[j-1]) {
                    j++;
                    continue;
                }
                int sum=num[j] + num[k];
                if(sum == target)
                {
                    triplet[0] = num[i];
                    triplet[1] = num[j++];
                    triplet[2] = num[k--];
                    ans.push_back(triplet);
                }else if(sum < target) {
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};
