#include <iostream>
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m == 0 && n==0) return 0;
        if(m==0) return median(B, n);
        if(n==0) return median(A, m);

        return findMedianSortedArraysRecur(A, m, B, n, max(0, (m+n)/2 - n), min(m-1, (m+n)/2));
    }

    double findMedianSortedArraysRecur(int A[], int m, int B[], int n, int left, int right)
    {
        if(left > right) {
            return findMedianSortedArraysRecur(B, n, A, m, max(0, (m+n)/2 - m), min(n-1, (m+n)/2));
        }
        int i = (left+right)/2;
        int j = (m+n)/2 - i - 1;

        if(j>=0 && A[i] < B[j]) {
            return findMedianSortedArraysRecur(A, m, B, n, i+1, right);
        }
        else if(j<n-1 && A[i] > B[j+1]) {
            return findMedianSortedArraysRecur(A, m, B, n, left, i-1);
        }
        else {
            if((m+n) % 2 == 1) return A[i];
            else if(i>0) {
                return (A[i] + max(A[i-1], B[j]))/2.0;
            } else{
                return (A[i] + B[j])/2.0;
            }
        }
    }

    double median(int A[], int m){
        if(m%2==1) return A[m/2];
        else{
            return (A[m/2]+A[m/2-1])/2.0;
        }
    }

    int max(int a, int b)
    {
        return a>b? a:b;
    }

    int min(int a, int b) {
        return a<b?a:b;
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    int A[]={100000};
    int B[]={100001};

    std::cout<<std::fixed<< sl->findMedianSortedArrays(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0]))<<std::endl;

    return 0;
}
