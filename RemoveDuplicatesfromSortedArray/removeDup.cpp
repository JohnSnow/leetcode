class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0 || n ==1) return n;

        int i = 0;
        int j = 1;

        for(; j < n; j++) {
            if(A[j] != A[i]) {
                if(j -i > 1) {
                    A[i+1] = A[j];
                }
                i++;
            }
        }
        return i+1;
    }
};
