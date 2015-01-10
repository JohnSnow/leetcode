class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0) return 0;

        int i, j;
        i = 0;
        j = n -1;
        while(i<j) {
            while (A[j] == elem && j > i) j--;
            while(A[i] != elem && i <j) i++;
            if(j > i) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        if(A[i] == elem) return 0;
        return i+1;

    }
};
