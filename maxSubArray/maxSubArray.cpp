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
        return maxSubArray(A, 0, n-1);
    }

    int maxSubArray(int A[], int left, int right) {
        if (left > right) {
            return INT_MIN;
        }
        if(left == right) {
            return A[left];
        }
        int mid = left + (right - left)/2;
        int max_left = maxSubArray(A, left, mid);
        int max_right = maxSubArray(A, mid+1, right);

        int max_left_bd = INT_MIN;
        int sum_left_bd = 0;
        for(int i= mid; i >=left; i--) {
            sum_left_bd += A[i];
            if (sum_left_bd > max_left_bd) {
                max_left_bd = sum_left_bd;
            }
        }

        int max_right_bd = INT_MIN;
        int sum_right_bd = 0;
        for (int j = mid + 1; j <=right; j++) {
            sum_right_bd += A[j];
            if (sum_right_bd > max_right_bd) {
                max_right_bd = sum_right_bd;
            }
        }
        int max_bd = max_left_bd + max_right_bd;
        return (max_left > max_right)? ((max_left > max_bd)? max_left: max_bd):((max_right > max_bd)? max_right: max_bd);
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
