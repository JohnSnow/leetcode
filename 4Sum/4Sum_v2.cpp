#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> quad(4,0);

        if(num.size() < 4) return ans;

        std::sort(num.begin(), num.end());

        for(unsigned i = 0; i< num.size() - 3; i++) {
            if(i > 0 && num[i] == num[i - 1]) {
                continue;
            }

            for(unsigned j = i+1; j < num.size() - 2; j++) {
                if(j > i+1 && num[j] == num[j - 1]) {
                    continue;
                }

                int newTarget = target - num[i] - num[j];
                unsigned k=j+1, l = num.size() -1;

                while(k < l) {
                    int sum = num[k] + num[l];
                    if(k> j+1 && num[k] == num[k-1]) {
                        k++;
                        continue;
                    }
                    if(sum == newTarget) {
                        quad[0] = num[i];
                        quad[1] = num[j];
                        quad[2] = num[k++];
                        quad[3] = num[l--];
                        ans.push_back(quad);
                    }else if(sum < newTarget) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
