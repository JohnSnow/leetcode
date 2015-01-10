class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;

        int f0 = 1;
        int f1 = 1;

        for(int i = 2; i <=n; i++) {
            int tmp = f0 + f1;
            f0 = f1;
            f1 = tmp;
        }

        return f1;
    }
};
