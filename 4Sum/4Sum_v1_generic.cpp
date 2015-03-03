#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using std::vector;
using std::set;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        return findKSumInSortedArr(num, 0, 4, target);
    }


    vector<vector<int> > findKSumInSortedArr(vector<int> &num, int begin ,int k, int target)
    {
        vector<vector<int> > ans;
        vector<int> tuple;
        set<int> visited;

        if(k == 2)
        {
            int i= begin;
            int j = num.size() - 1 ;
            while(i < j)
            {
                int sum = num[i] + num[j];
                if(sum == target && visited.find(num[i]) == visited.end()){
                    tuple.clear();
                    visited.insert(num[i]);
                    visited.insert(num[j]);
                    tuple.push_back(num[i]);
                    tuple.push_back(num[j]);
                    ans.push_back(tuple);
                    i++; j--;
                }
                else if(sum < target) i++;
                else j--;
            }
        }
        else
        {
            for(size_t i = begin; i< num.size(); i++) {
                if(visited.find(num[i]) == visited.end()) {
                    visited.insert(num[i]);
                    vector<vector<int> > subRet = findKSumInSortedArr(num, i+1, k-1, target - num[i]);

                    if(!subRet.empty()) {
                        for(size_t j=0; j < subRet.size(); j++) {
                            subRet[j].insert(subRet[j].begin(), num[i]);
                        }
                        ans.insert(ans.end(), subRet.begin(), subRet.end());
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution * sl = new Solution();
    int a[] = {1, 0, -1, 0, -2, 2};

    vector<int> num(a, a+sizeof(a)/sizeof(a[0]));

    vector<vector<int> > res = sl->fourSum(num, 0);

    for(auto vv : res) {
        for(auto el : vv) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
