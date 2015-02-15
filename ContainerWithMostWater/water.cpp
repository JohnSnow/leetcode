#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size <=1) return 0;

        int ret = 0;
        int i=0;
        int j = size - 1;

        int h = 0;
        int area = 0;

        while(i<j) {
            if(height[j] > height[i]) {
                h = height[i];
                area = h * (j-i);
                while(i <j && height[++i] <= h);
            } else {
                h = height[j];
                area = h *(j - i);
                while(i<j && height[--j] <=h) ;
            }
            if(area > ret) ret = area;
        }

        return ret;
    }
};
