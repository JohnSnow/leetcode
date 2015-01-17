#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxProduct(int A[], int n) {
        int current_max_proc = A[0];
        int previous_min_proc = A[0];
        int previous_max_proc = A[0];
        int Ans = A[0];

        for(int i=1; i< n;i ++) {
            current_max_proc = max3(
                    previous_max_proc * A[i],
                    previous_min_proc * A[i],
                    A[i]);
            int current_min_proc = min3(
                    previous_max_proc * A[i],
                    previous_min_proc * A[i],
                    A[i]);

            Ans = std::max(Ans, current_max_proc);
            previous_max_proc = current_max_proc;
            previous_min_proc = current_min_proc;
        }
        return Ans;
    }

    inline int max3(int a, int b, int c){
        if(a>b) {
            if(a >c) return a;
            else return c;
        } else {
            if(b > c) return b;
            else return c;
        }
    }

    inline int min3(int a, int b, int c) {
        if(a < b) {
            if (a < c) return a;
            else return c;
        } else {
            if(b < c) return b;
            else return c;
        }
    }
};
