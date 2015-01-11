#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }

    int findMin(vector<int> &num, int l, int u) {

        if(l == u || num[l] < num[u]) return num[l];

        int m = (l + u) / 2;

        if(num[m] >= num[l]) {
            return findMin(num, m+1, u);
        } else{
            return findMin(num, l, m);
        }
    }
};

int main(int argc, char *argv[])
{
    int a[3] = {3, 1,2};
    vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
    Solution *sl = new Solution();
    std::cout << sl->findMin(vec) << std::endl;
    return 0;
}
