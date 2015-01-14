#include <iostream>
#include <algorithm>

class Solution {
public:
// divide and conquer , not accepted, time limit
/*    int maxProduct(int A[], int n) {*/
        //if(n == 0) return 0;
        //return maxProc(A, 0, n-1);
    //}

    //int maxProc(int A[], int l, int h)
    //{
        //if(l > h) return 0;
        //if(l == h) return A[l];

        //int mid = (l+h)/2;

        //int max_left_proc = maxProc(A, l, mid -1);
        //int max_right_proc = maxProc(A, mid +1, h);

        //int max_cross = 0;

        //int max_left_aj;
        //int max_right_aj;

        //int tmp = 1;
        //if(l == mid) {
            //max_left_aj = 1;
        //} else {
            //tmp = max_left_aj = A[mid -1];
            //for(int k = mid -2; k >=l; k--) {
                //tmp *= A[k];
                //if(tmp > max_left_aj) {
                    //max_left_aj = tmp;
                //}
            //}
        //}

        //if(mid == h) {
            //max_right_aj = 1;
        //} else{
            //tmp = max_right_aj = A[mid+1];
            //for(int k = mid+2; k<=h; k++) {
                //if(tmp > max_right_aj) {
                    //max_right_aj = tmp;
                //}
            //}
        //}

        //max_cross = std::max(std::max(A[mid], A[mid] * max_left_aj), std::max(A[mid] * max_right_aj, A[mid]*max_left_aj*max_right_aj));

        //return max_left_proc>max_right_proc? (max_left_aj>max_cross?max_left_aj:max_cross) : (max_right_aj >max_cross?max_right_aj:max_cross);
    /*}*/

    int maxProduct(int A[], int n) {
        if(n == 0) return 0;
        if(n == 1) return A[0];

        int i =0;
        int tmp = 0;
        int max_so_far = 0;
        while(i < n) {
            while( i < n && A[i] == 0) {
                i++;
            }
            if(i == n) break;

            tmp = 1;
            int start = i;
            while(i<n) {
                if(tmp ==0) tmp =1;
                while(i<n && A[i] > 0) {
                    tmp *= A[i];
                    i++;
                }
                if(i == n || A[i] == 0) {
                    if(tmp > max_so_far) {
                        max_so_far = tmp;
                    }
                    break;
                }
                int j = i;
                while(i<n && A[i] < 0) {
                    tmp *= A[i];
                    i++;
                }
                int diff = i - j;
                if(diff  == 1) {
                    if(j > start) {
                        tmp /= A[j];
                    }
                    if(tmp > max_so_far) {
                        max_so_far  = tmp;
                    }
                    tmp = 0;
                } else if((diff & 0x1) == 1){
                    tmp /= A[i-1];
                    if(tmp > max_so_far) {
                        max_so_far = tmp;
                        tmp /= A[j];
                    }
                }
                if(A[i]==0 || i==n) {
                    if(tmp>max_so_far) {
                        max_so_far = tmp;
                    }
                    break;
                }
            }

        }
        return max_so_far;
    }
};

int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    int a[3] = {-2, 0, -1};
    std::cout << sl->maxProduct(a, 3) << std::endl;
    return 0;
}
