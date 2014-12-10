#include <iostream>
#include <algorithm>
#include <climits>

class Solution {
public:
    // O(n)
    //int maxSubArray(int A[], int n) {
        //if (n == 0) {
            //return 0;
        //}

        //int max_ending_here, max_so_far;
        //max_ending_here = max_so_far = A[0];

        //for (int i = 1; i < n; i++) {
            //max_ending_here = std::max(A[i], max_ending_here + A[i]);
            //max_so_far = std::max(max_so_far, max_ending_here);
        //}
        //return max_so_far;
    //}
    
    // divide and conquer
    int maxSubArray(int A[], int n) {

    }

    int maxSubArray(int A[], int idx_st, int idx_end, int& maxVal) {
        
    }
};


int main(int argc, const char *argv[])
{
    Solution *sl = new Solution();
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int A_len = 9;

    std::cout << sl->maxSubArray(A, A_len) << std::endl;

    return 0;
}
